#include <iostream>
#include <unordered_map>
#include <map>
#include "users.h"
#include "tweet.h"
#include <string>
#include <vector>
using namespace std;

class Twitterak
{
    private:
        unordered_map<string , Common*> musers;
        map <string , vector<Tweet> > mhashtag;
        //save
    public:
    bool checkin = 0;
    string color ;
    string temp = "";
    string save = ""; //for checkig our account (personal, company , ....)
    void signup(vector<string> &vec1);
    void login(vector<string>&vec2);
    void ckeck_id(string &id);
    void logout();
    void choice_login();
    void menu();
    void show(string);
    //void help();
    void edit_profile(string , string);
    void delete_account();
    void check_space(string&) ;
    void findhash(string, Tweet);
    void showhash(string);
    void put_user();
    void put_hashtag();
    void ptweet();
    void pfollow();
    void in_user();
    void in_tweet();
    void in_follow();
    void in_hashtag();
    void push_hashtag(string, Tweet);

    
};