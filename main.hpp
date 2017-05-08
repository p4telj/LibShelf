/*
 * main.hpp
 * LibraryManagement
 *
 * Jimil Patel <pateljim@umich.edu>
 * https://github.com/pateljim/libraryManagement
 *
 */

#ifndef main_h
#define main_h

class Loader : public Wt::WApplication
{
public:
    Loader(const Wt::WEnvironment& env);
    
private:
    Wt::WLineEdit *nameEdit_;
    Wt::WText *greeting_;
    
    void greet();
};


#endif /* main_h */
