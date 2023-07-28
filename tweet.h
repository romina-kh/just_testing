#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


class Common;
class Tweet
{
    private:

        vector<Common*>likers;
        string tweet;
        string Date ;    
        int number;
        

    public:

        void Set_Tweet(string);
        void set_number(int);
        string get_classtweet();
        int get_number();
        void likes(Common* ,Common* , int);
        void dislike(Common* ,Common* , int);
        void show_numberlikes(Common*, int);
        void show_likers(Common*, int);
        int liker_size();
        void Set_date();
        string get_Date();


};


#endif