/*
 * database.hpp
 * LibraryManagement
 *
 * Jimil Patel <pateljim@umich.edu>
 * https://github.com/pateljim/libraryManagement
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "database.hpp"

using namespace std;

/* CONSTRUCTOR / DESTRUCTOR */
// custom constructor: specifies debug mode
database::database(bool _debug) : debug(_debug) {}

// destructor : deletes connection, statement, result objs
database::~database() { delete connection; delete script; delete result; }


/* MYSQL SERVER CONFIGURATION / CONNECTION HANDLING */
// accesses server config file
void database::checkConfig() {
    ifstream config("libMa.ini");
    if(!config.is_open()) {
        // call main.checkConfig_broken to display
        fixConfig();
    }
    // call main.checkConfig_reading to display
    // logic here to read based on config format : store server, server_usr, server_pwd & default tables
}

// if config file broken, writes a new one with defaults
void database::fixConfig() {
    
}

// connects to database : failure outputs error & exits
void database::connect() {
    
}


/* USER MANAGEMENT */
// logs user in : returns success / failure
bool database::usr_login() {
    std::time_t result = std::time(nullptr);
    log.open("libMa.log", std::ios_base::app);
    logger << "Version " << VERSION << " Application Executed: " << std::asctime(std::localtime(&result)) << endl;
    if(debug) cout << logger.str();
    // record acccess # too
    return 0;
}

// creates new user : returns success / failure
bool database::usr_reg(std::string makeAdmin) {
    return 0;
}

// logs user out : returns success / failure
bool database::usr_logout() {
    return 0;
}

// validates username password combo with database
bool database::usr_validate(std::string usr_in, std::string pwd_in) {
    return 0;
}

// resalts after every account access
void database::usr_resalt(std::string usr_in, std::string pwd_in) {
    
}

// validates email address during registration
// thanks to: http://etutorials.org/Programming/secure+programming/Chapter+3.+Input+Validation/3.9+Validating+Email+Addresses/
bool database::email_validate(const char *address_in) {
    int count = 0;
    const char *c, *domain;
    string x = "()<>@,;:\\\"[]";
    static char *rfc822_specials = new char[x.size()+1];
    strcpy(rfc822_specials, x.c_str());
    
    /* first we validate the name portion (name@domain) */
    for (c = address_in;  *c;  c++) {
        if (*c == '\"' && (c == address_in || *(c - 1) == '.' || *(c - 1) ==
                           '\"')) {
            while (*++c) {
                if (*c == '\"') break;
                if (*c == '\\' && (*++c == ' ')) continue;
                if (*c <= ' ' || *c >= 127) return 0;
            }
            if (!*c++) return 0;
            if (*c == '@') break;
            if (*c != '.') return 0;
            continue;
        }
        if (*c == '@') break;
        if (*c <= ' ' || *c >= 127) return 0;
        if (strchr(rfc822_specials, *c)) return 0;
    }
    if (c == address_in || *(c - 1) == '.') return 0;
    
    /* next we validate the domain portion (name@domain) */
    if (!*(domain = ++c)) return 0;
    do {
        if (*c == '.') {
            if (c == domain || *(c - 1) == '.') return 0;
            count++;
        }
        if (*c <= ' ' || *c >= 127) return 0;
        if (strchr(rfc822_specials, *c)) return 0;
    } while (*++c);
    
    delete[] rfc822_specials;
    return (count >= 1);
}




