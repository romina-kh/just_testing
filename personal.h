#ifndef PERSONAL_H
#define PERSONAL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "users.h"

using namespace std;

class Personal : public Common
{
    private:
        string Age;
        string Phone_Number;
        string Country;
        string Link;
        string Bio;
        string Header;

    public:
        int Set_Bio(string Bio);
        string Get_Bio();

        int Set_Country(string Country);
        string Get_Country();

        int Set_Link(string Link);
        string Get_Link();

        int Set_Age(string Age);
        string Get_Age();

        int Set_Phone(string Phone_Number);
        string Get_Phone();

        void profile_me();
        void profile_other();

        void edit_pro(string , string);
};

#endif