#ifndef USERS_H
#define USERS_H

#include <iostream>
using namespace std;

class Common //parent 
{
    private:
        string Name;
        string User_Name;
        size_t Password;
        string Picture; //profile pic
        string Header; //header color
        int Followers;
        int Follwing;

    public:
        
        int Set_Name(string Name);
        string Get_Name();

        int Set_User(string User_Name);
        string Get_User();

        int Set_Password(string Password);
        size_t Get_Password();
};

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
        int Set_Bio_p(string Bio);
        string Get_Bio_p();

        int Set_Country_p(string Country);
        string Get_Country_p();

        int Set_Link_p(string Link);
        string Get_Link_p();

        int Set_Age(string Age);
        string Get_Age();

        int Set_Phone_p(string Phone_Number);
        string Get_Phone_p();
};

class Anonymous : public Common
{

};

class Company : public Common
{
    private:
        string Bio;
        string Phone_Number;
        string Country;
        string Link;


    public:
        int Set_Bio_c(string Bio);
        string Get_Bio_c();

        int Set_Country_c(string Country);
        string Get_Country_c();

        int Set_Link_c(string Link);
        string Get_Link_c();

        int Set_Phone_c(string Phone_Number);
        string Get_Phone_c();


};









#endif