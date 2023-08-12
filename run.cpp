#include <iostream>
#include <stdlib.h>
#include "users.h"
#include "twitterak.h"

using namespace std;



int main()
{
    Twitterak app;
    app.in_user();
    app.in_tweet();
    app.in_follow();
    app.in_hashtag();
    app.menu();
    

    return 0;
}