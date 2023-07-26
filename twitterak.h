#include <iostream>
#include <unordered_map>
#include "users.h"
#include <string>
#include <vector>

using namespace std;

class Twitterak
{
    private:
        unordered_map<string , Personal*> mpersonal;
        unordered_map<string , Company*> mcompany;
        unordered_map<string , Anonymous*> manonymous;
    public:
    bool checkin = 0;
    string temp = "";
    void signup(vector<string> &vec1);
    void ckeck_id(string &id);
    void menu();
};