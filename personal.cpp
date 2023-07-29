#include <iostream>
#include <string>
#include <vector>
#include "users.h"
#include "company.h"
#include "personal.h"


using namespace std;



//---------------------------------------------------------------------------------
//personal
int Personal::Set_Bio(string Bio)//160 char(checked)
{
    
    if(Bio.size() < 161)
    { 
        this-> Bio = Bio;
        return 1; 
    }
    else if (Bio == "")
    {
        this-> Bio = Bio;
    }
    else
    {
        cout << "! Error please Enter another Biography.\n";
        return 0 ;
    }
}


string Personal::Get_Bio()
{
    return Bio;
}


int Personal::Set_Country(string Country)
{
    if(Country.size() < 51)
    { 
        this-> Country = Country;
        return 1; 
    }
    else if (Country == "")
    {
        this-> Country = Country;
    }
    else
    {
        cout << "! Error please Enter another Country.\n";
        return 0 ;
    }
}


string Personal::Get_Country()
{
    return Country;
}

int Personal::Set_Link(string Link)
{
    if(Link.size() < 500)
    { 
        this-> Link = "https://" + Link;
        return 1; 
    }
    else if (Link == "")
    {
        this-> Link = Link;
        return 0;
    }
    else
    {
        cout << "! Error please Enter another Link.\n";
        return 0 ;
    }
    
}


string Personal::Get_Link()
{
    return Link;
}


int Personal::Set_Age(string Age)
{
    if(Age[0]>=48 && Age[0]<=57 &&
       Age[1]>=48 && Age[1]<=57 &&
       Age[2]>=48 && Age[2]<=57 &&
       Age[3]>=48 && Age[3]<=57 &&
       Age[4]==47 &&
       Age[5]>=48 && Age[5]<=57 &&
       Age[6]>=48 && Age[6]<=57 &&
       Age[7]==47 &&
       Age[8]>=48 && Age[8]<=57 &&
       Age[9]>=48 && Age[9]<=57 )
    {
       this->Age = Age;
       return 1 ;  
    }
    else
    {
       cout << "! Error please Enter your birthday correctly.\n";
       return 0 ;
    }
}


string Personal::Get_Age()
{
    return Age;
}


int Personal::Set_Phone(string Phone_Number)
{
    int counter = 0;
    if(Phone_Number.size()==12)
    {
        for( int i=0 ;i<Phone_Number.size();i++)
        {
            if(Phone_Number[i]>='0' && Phone_Number[i]<='9')
            {
                counter++;
            }

        }
        if (counter == 12)
        {
            this->Phone_Number = Phone_Number;
            return 1 ;  
        }
        else
        {
            cout << "! You are only allowed to enter numbers in this section.\n";
        }
    }
    else
    {
       cout << "! Error please Enter your phone number correctly.\n" ;
       return 0 ;
    }
    

}

string Personal::Get_Phone()
{
    return Phone_Number;
}



void Personal:: profile_me()
{
            //musers[temp]->Get_Header();
            //header(color);
            cout << "$ Name : ";
            cout << Get_Name()<< endl ;
            cout << "$ Username : ";
            cout << Get_User() << endl ;
            cout << "$ Age : ";
            cout << Get_Age() << endl ;
            cout << "$ Phone number : ";
            cout << Get_Phone() << endl ;
            cout << "$ Bio : ";
            cout << Get_Bio() << endl ;
            cout << "$ Country : ";
            cout << Get_Country() << endl ;
            cout << "$ Link : ";
            cout << Get_Link() << endl ;
            cout << "$ follower : " ;
            cout << Get_followers() << endl ;
            cout << "$ following : " ;
            show_following() ;
}            
       
void Personal:: profile_other()
{  
            // musers[temp]->Get_Header();
            // header(color);
            cout << "$ Name : ";
            cout << Get_Name()<< endl ;
            cout << "$ Username : ";
            cout << Get_User() << endl ;
            cout << "$ Age : ";
            cout << Get_Age() << endl ;
            cout << "$ Bio : ";
            cout << Get_Bio() << endl ;
            cout << "$ Country : ";
            cout << Get_Country() << endl ;
            cout << "$ Link : ";
            cout << Get_Link() << endl ;
            cout << "$ follower : " ;
            cout << Get_followers() << endl ;
            cout << "$ following : " ;
            cout << Get_following() << endl ;
            
}