/*
 * security.hpp
 * LibraryManagement
 *
 * Jimil Patel <pateljim@umich.edu>
 * https://github.com/pateljim/libraryManagement
 *
 */

#ifndef SECURITY_hpp
#define SECURITY_hpp

#include <string>

// uses hash / salt to lightly encrypt password
void encrypt(std::string &password, std::string &salt);
// returns SHA1 hash of unhashed string
void doHash(std::string &unhashed);
// returns randomized salt from unsalted string
void doSalt(std::string &salt);
// user verification
bool hasClearance(std::string input, const std::string &salt, const std::string &hashed);
// creates random string
// thanks to: http://stackoverflow.com/users/13760/carl
std::string randomString(size_t length);

#endif /* security_hpp */
