/*
 * security.cpp
 * LibraryManagement
 *
 * Jimil Patel <pateljim@umich.edu>
 * https://github.com/pateljim/libraryManagement
 *
 */

#include <string>
#include <openssl/sha.h>
#include <openssl/crypto.h>

#include "security.hpp"

// uses hash / salt to lightly encrypt password
void encrypt(std::string &password, std::string &salt) {
    doSalt(salt);
    password = salt + password;
    doHash(password);
}

// returns SHA1 hash of unhashed string
void doHash(std::string &unhashed_str) {
    char unhashed_cstr[unhashed_str.size()];
    strncpy(unhashed_cstr, unhashed_str.c_str(), unhashed_str.size());
    
    size_t length = sizeof(unhashed_cstr);
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)unhashed_cstr, length, hash);
    
    char hashed_cstr[SHA_DIGEST_LENGTH*2+1];
    for(int i = 0; i < SHA_DIGEST_LENGTH; ++i)
        sprintf(&hashed_cstr[i*2], "%02x", (unsigned int)hash[i]);
    unhashed_str = hashed_cstr;
}
// returns randomized salt from unsalted string
void doSalt(std::string &salt) { salt = randomString(10); }

// user verification
bool hasClearance(std::string input, const std::string &salt, const std::string &hashed) {
    std::string hash_comparison = salt + input;
    doHash(hash_comparison);
    return hash_comparison == hashed;
}

// creates random string
// thanks to: http://stackoverflow.com/users/13760/carl
std::string randomString(size_t length) {
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

