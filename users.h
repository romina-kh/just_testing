#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>
#include <vector>
#include "tweet.h"
#include <map>

using namespace std;
class Common //parent 
{
    friend void Tweet:: likes(Common* currentuser, Common* target, int index);
    friend void Tweet:: show_numberlikes( Common *target, int index);
    friend void Tweet:: show_likers(Common* target, int index);
    friend void Tweet:: dislike(Common* currentuser ,Common* target, int index);
    private:
        map<int ,Tweet> mtweet;// map<string , vector<Tweet*>>
        vector<string> vecfollowing ;
        string Name;
        string User_Name;
        size_t Password;
        string Picture; //profile pic
        string Header; //header color
        string Age;
        string Phone_Number;
        string Country;
        string Link;
        string Bio;
        int followers = 0;
        

        int index = 0 ;

    public:
        
        virtual int Set_Name(string Name);
        virtual string Get_Name();

        virtual int Set_User(string User_Name);
        virtual string Get_User();

        virtual int Set_Password(string Password);
        virtual size_t Get_Password();

        virtual int Set_Bio(string Bio){};
        virtual string Get_Bio(){};

        virtual int Set_Country(string Country){};
        virtual string Get_Country(){};
        
        virtual int Set_Link(string Link){};
        virtual string Get_Link(){};
        
        virtual int Set_Age(string Age){};
        virtual string Get_Age(){};

        virtual int Set_Phone(string Phone_Number){};
        virtual string Get_Phone(){};

        virtual void Set_Header(string Header);
        virtual string Get_Header();

        virtual void push_tweet(Tweet t);
        virtual void get_tweet();
        virtual void get_tweet1(int index);
        virtual void delete_tweet(int number);
        virtual void edit_tweet(int nUmber) ;
        virtual string backstring(int number) ;

        virtual void set_index();
        virtual int get_index(){return index;}

        //virtual void Set_following(int following);
        virtual int Get_following() ;//

        virtual void Set_followers(int followers);//
        virtual int Get_followers() ;//

        virtual void add_following(string) ;
        virtual void show_following() ;
        virtual void increase_follower();

        virtual void profile_me(){};
        virtual void profile_other(){};
        virtual void edit_pro(string ,string ){};

};








#endif