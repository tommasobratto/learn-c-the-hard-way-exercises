// This is a simple Database program from ex. 17 of Learn C The Hard Way.
// It is capable of storing addresses of fixed memory size and has a fixed
// number of rows.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// define pre-proc constant values
#define MAX_DATA 512
#define max_rows 100

// create an address struct for an example User registration form
struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

// create a database struct
struct Database {
    struct Address rows[max_rows];
};

// create a database connection struct
struct Connection {
    // The file is where the database data is going to be saved
    FILE *file;
    // The *db pointer is where the actual database information is going to be accessed
    // by the connection struct
    struct Database *db;
};

void Database_close(struct Connection *conn)
{
    if(conn) {
        // Close file
        if(conn->file) fclose(conn->file);
        // Free allocated memory for database struct inside connection struct
        if(conn->db) free(conn->db);
        // Free allocated memory for connection struct
        free(conn);
    }
}

// create an exit function to terminate the program
// if there are any errors
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    // Database_close(conn);
    exit(1);
}

// print the chosen address
void Address_print(struct Address *addr)
{
    // print the index number, the name and the email
    // of the chosen user/address
    printf("%d %s %s\n",
        addr->id, addr->name, addr->email);
}

// Loads database: How? (see fread)
void Database_load(struct Connection *conn)
{
    // fread statement: fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
    // fread function reads 'nitems' (number of items), each of value 'size' of bytes,
    // from the file 'stream', storing them at the location of 'ptr'
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    // If rc doesn't equal to 1, die() gets called with a custom error message
    if(rc != 1) die("Failed to load database");
}

// Opens database
struct Connection *Database_open(const char *filename, char mode)
{
    // The struct connection gets an instance of itself allocated in memory
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

    // The database inside the connection gets allocated in memory
    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error");

    if(mode == 'c') {
    // If CLI argument is equal to 'c', open file and create text file for writing
        conn->file = fopen(filename, "w");
    } else {
    // else open file and open for reading and writing
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            // call the load function
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{
    if(conn) {
        // Close file
        if(conn->file) fclose(conn->file);
        // Free allocated memory for database struct inside connection struct
        if(conn->db) free(conn->db);
        // Free allocated memory for connection struct
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);
    // Set the file position indicator to the beggining of the file

    // fwrite statement: fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
    // fwrite writes 'nitems' of 'size' bytes to file 'stream', obtaining them from memory location 'ptr'
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.");

    /* fflush forces write of all buffered data/update of 'stream' file.
     * It seems to finalize the fwrite function called earlier, 
     * essentially saving the added content in the opened 'stream' file. */
    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn, int rows)
{
    int i = 0;
    max_rows = rows;

    // for each row make a prototype address (template)
    for(i = 0; i < max_rows); i++) {
        struct Address addr = {.id = i, .set = 0};
        // assign it to the database
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    // initialise an address struct
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first.");

    /* Wut... so 'set' is a value tied to the address struct
     * that signals some kind of 'full' or 'active' status for
     * that particular address, amirite? */ 
    addr->set = 1;
    // WARNING: bug incoming

    /* Initialise a 'res' variable
     * and set it to contain a string copy of the address name, ecc. 
     * strncpy(dst, src, n);
     * Copies the string src to dst, filling in the rest with 'n' number of chars.
     * WAT. */
    char *res = strncpy(addr->name, name, MAX_DATA);
    addr->name[MAX_DATA - 1] = '\0';
    // demonstrate bug
    if(!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    addr->email[MAX_DATA - 1] = '\0';
    if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
    // initialise an address struct
    struct Address *addr = &conn->db->rows[id];

    // If there is an address with the 'id' argument,
    // print it
    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    // to 'delete' set the address to '0'
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    // initialise a db pointer
    int i = 0;
    struct Database *db = conn->db;

    // for each row check current address for a 'cur->set value'
    for(i = 0; i < max_rows; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            // and print the address
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    /* Define command line interface */

    if(argc < 3) die("USAGE: ex16 <dbfile> <action> [action params]");
    // Filename relates to the first argument appended
    char *filename = argv[1];
    // Action relates to 2nd argument plus a char-parameter
    char action = argv[2][0];
    // Open database
    struct Connection *conn = Database_open(filename, action);

    int id = 0;

    // Converts the 3rd argument character to integer
    // to equal it to id
    if(argc > 3) id = atoi(argv[3]);
    // If id is major than the number of rows, it gets rejected
    if(id >= max_rows) die("There's not that many records");

    switch(action) {
        // create database
        case 'c':
            if(argc != 4 || action != atoi(argv[3])) die("Need a database row number");
            Database_create(conn, rows);
            Database_write(conn);
            break;

        // get address using id
        case 'g':
            if(argc != 4) die("Need an id to get");

            Database_get(conn, id);
            break;

        // set address with id, name, email
        case 's':
            if(argc != 6) die("Need id, name, email to set");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        // delete address using id
        case 'd':
            if(argc != 4) die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        // list addresses in database
        case 'l':    
            Database_list(conn);
            break;

        default: 
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}
