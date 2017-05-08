/*
 * main.cpp
 * LibraryManagement
 *
 * Jimil Patel <pateljim@umich.edu>
 * https://github.com/pateljim/libraryManagement
 *
 */

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

#include "main.hpp"

Loader::Loader(const Wt::WEnvironment& env)
: Wt::WApplication(env)
{
    setTitle("Hello world");
    
    root()->addWidget(new Wt::WText("Your name, please ? "));
    nameEdit_ = new Wt::WLineEdit(root());
    Wt::WPushButton *button = new Wt::WPushButton("Greet me.", root());
    root()->addWidget(new Wt::WBreak());
    greeting_ = new Wt::WText(root());
    button->clicked().connect(this, &Loader::greet);
}

void Loader::greet()
{
    greeting_->setText("Hello there, " + nameEdit_->text());
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
    return new Loader(env);
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, &createApplication);
}
