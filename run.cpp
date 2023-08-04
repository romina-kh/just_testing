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
    app.menu();
    

    return 0;
}