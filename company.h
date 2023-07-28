#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "users.h"

using namespace std;

class Company : public Common
{
    private:
        string Bio;
        string Phone_Number;
        string Country;
        string Link;


    public:
        int Set_Bio(string Bio)override;
        string Get_Bio();

        int Set_Country(string Country);
        string Get_Country();

        int Set_Link(string Link);
        string Get_Link();

        int Set_Phone(string Phone_Number);
        string Get_Phone();


};

#endif