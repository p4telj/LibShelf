#ifndef DATABASE_H
#define DATABASE_H

/*
 * database.hpp
 * LibraryManagement
 *
 * Jimil Patel <pateljim@umich.edu>
 * https://github.com/pateljim/libraryManagement
 *
 */

#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <mysql.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <fstream>

#include <vector>

#define VERSION 1.0

class database {
public:
    /* CONSTRUCTOR / DESTRUCTOR */
    // custom constructor : specifies debug mode
    database(bool _debug = false);
    // custom copy constructor : disabled
    database(const database &other) = delete;
    // overloaded assignment operator : disabled
    database* operator=(const database &other) = delete;
    // destructor : deletes connection, statement, result objs
    ~database();
    
    /* MYSQL SERVER CONFIGURATION / CONNECTION HANDLING */
    // accesses server config file
    void checkConfig();
    // connects to database : failure outputs error & exits
    void connect();
    
    /* USER MANAGEMENT */
    // logs user in : returns success / failure
    bool usr_login();
    // creates new user : returns success / failure
    bool usr_reg(std::string makeAdmin = "0");
    // logs user out : returns success / failure
    bool usr_logout();
    

    
    /* notes: 
        library is available for different organizational use---
            if you want to create a library for your organization, you select that option
            the first user to create a library becomes an admin. the others can only be an admin if they are /
            / designated admins by another admin. users are specific to their library
        the config file will include: 1) default mysql database login 2) the default tables / columns for
        initial setup of every library
     */
    
    
    



private:
    // if debug : outputs errors/messages to console | otherwise, outputs to log
    bool debug;
    std::ostringstream logger;
    std::ofstream log;
    
    /* MYSQL SERVER CONFIGURATION / CONNECTION HANDLING [2] */
    // if config file broken, writes a new one with defaults
    void fixConfig();
    
    // server properties
    std::string server;
    std::string server_database;
    std::string server_usr;
    std::string server_pwd;
    
    // database properties
    std::vector<std::string> defaultdb;
    std::string db;
    sql::Connection *connection;
    sql::Statement *script;
    sql::ResultSet *result;
    
    /* USER MANAGEMENT [2] */
    // validates username password combo with database
    bool usr_validate(std::string usr_in, std::string pwd_in);
    // resalts after every account access
    void usr_resalt(std::string usr_in, std::string pwd_in);
    // validates email address during registration
    // thanks to: http://etutorials.org/Programming/secure+programming/Chapter+3.+Input+Validation/3.9+Validating+Email+Addresses/
    bool email_validate(const char *address_in);
    
    // user properties
    std::string usr_email;
    std::string usr_fname;
    std::string usr_mname = "";
    std::string usr_lname;
    std::string usr_city;
    std::string usr_street;
    std::string usr_state;
    int usr_zip;
    std::string usr_country;
    int usr_phone;
    bool usr_admin;
};

#endif /* database_hpp */
