#include <iostream>
#include <string>
#include <vector>
#include "users.h"
#include "company.h"
#include "personal.h"
#include "anonymous.h"
#include "tweet.h"

using namespace std;

void Anonymous :: push_tweet(Tweet t)
{
    cout << "! This account is not allowed to tweet.\n";
}

void Anonymous::edit_tweet(int nUmber)
{
cout << "! This account is not allowed to edit tweet.\n";

}
 
void Anonymous::get_tweet()
{
    
}

void Anonymous::delete_tweet(int number)
{
    cout << "! This account is not allowed to edit tweet.\n";
}

void Anonymous :: get_tweet1(int index)
{
    
}



