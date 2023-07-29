#include <iostream>
#include <unordered_map>
#include <string>
#include "users.h"
#include "tweet.h"
#include "twitterak.h"
#include <bitset>
#include <functional>
#include <vector>
#include <sstream>
#include "company.h"
#include "personal.h"
#include "anonymous.h"


using namespace std ;

//objects of classe
//Common* user = nullptr;
Common* user = nullptr;
Tweet tweet_object;
//********************************************************************************************************************************************

void Twitterak::ckeck_id(string &id) //This function ckeck the reserved word and @
{
    if(id[0]=='@')
    {
        id.erase(0 , 1) ;
    }
    if(id=="exit" 
    || id=="edit" 
    || id=="login" 
    || id=="signup" 
    || id=="delete" 
    || id=="username" 
    || id== "help" )
    {
        cout << "! This is a reserved keyword. you can not choose it as your username.\n" ;
    }
    
}

//*********************************************************************************************************************************************************
void header(string color)
{
    
    cout << endl;
    cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    \n";
    cout << endl <<"              ";
    
    for(int i = 0 ; i < color.size() ; i++)
    {
        cout << "   " << color[i] << "    " ;
    }

    cout << endl;
    cout << endl;
    cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    \n";
}

//********************************************************************************************************************************************************
void Twitterak::check_space(string& str3)
{
    size_t pos ;
    // Find the first non-space character in the string
    for( int i=0 ;i<str3.size() ;i++)
    {
        pos = str3.find_first_not_of(" ");
        if (pos != string::npos)
        {
            str3.erase(0, pos);
        }
    } 
}

//************************************************************************************************************************************************************   
void seperator(string original , string& characters , string& numbers) //This function seprate username from ":" and tweet number
{
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] != ':')
        {
            characters += original[i];
        }
        else if (original[i] == ':')
        {
            for (int j = i+1; j < original.size(); j++)
            {
                if (isdigit(original[j]))
                {
                    numbers += original[j];
                }
            }
            break;
        }

    }

}

//********************************************************************************************************************************************

void Twitterak::menu()
{
    // welcome printing
    
    // system("Color 01");
    // cout << "W       O\n" ;
    // cout << "  E   C   M    to  | T | W | I | T | T | E | R | A | K |\n" ;
    // cout << "    L       E\n" ;
    system("Color 0F");
    cout << "* If you are not familiar with the commands of the program, use the <help> .\n";
    
    //----------------------------------------------------------------------------------
    
    string choice , r;//string that we use to separate words from each other(words between space)
    vector <string> vec1;
    bool flag1 = true;

    while(flag1==true)
    {

        cout << "> ";
        getline(cin ,choice);
        for (int i = 0 ; i < choice.size() ; i++)
        {
            choice[i] = tolower(choice[i]);
        }
        vec1.clear();
        stringstream word1(choice);

        while (getline(word1 , r , ' '))
        {
            vec1.push_back(r);
        }
        
        // if(vec1[0] == "help")
        // {
        //     help();
        // }
        if(vec1[0] == "signup" )
        {
            signup(vec1);
        }
        else if(vec1[0] == "login")
        {
            login(vec1);
        }
        else if(vec1[0] == "exit" || vec1[0]=="q" || vec1[0]=="quit")
        {
            string ask;
            cout << "? Are you sure?(y/n) : ";
            getline( cin , ask); 
            if (ask[0] == 'y')
            {
                cout << "* Good Bye.";
                exit(0);
            }
            else
            {
                menu() ;

            }
        }
        else
        {
            cout << "! Undefined command.\n";
        }
    }
}

//****************************************************************************************************************************************

void Twitterak::signup(vector<string>&vec1)
{
    
    string Name;
    string Age; 
    string Phone_Number;
    string Country;
    string Link;
    string Bio;
    string Password;
    string User;
    string choice_s;
    
    // while(flag == true)
        //========
        cout << "    > 1.organisation\n    > 2.personal\n    > 3.anonymous\n> ";
        //=========
        getline(cin ,choice_s);
        for (int i = 0 ; i < choice_s.size() ; i++)
        {
            choice_s[i] = tolower(choice_s[i]);
        }
        
        if (choice_s == "2")
        {
            save = "personal";
            user = new Personal;

            if(vec1.size()==1)
            {
                cout << "\n$ Username : ";
                cin >> User;
                ckeck_id(User);
                int check1 = user->Set_User(User);
                while (check1 > 0)
                {
                    cout << "$ Username : ";
                    cin >> User;
                    check1 = user->Set_User(User);
                }
                cout << endl ;

            }
            else
            {
                User=vec1[1];
                ckeck_id(User);
                int check1 = user->Set_User(User);
                while (check1 > 0)
                {
                    check1 = user->Set_User(User);
                }
                cout << endl ;
            }

            cout << "$ Name : ";
            cin >> Name;
            user->Set_Name(Name) ;
            cout << endl ;
            
            cout << "$ Age : ";
            cin >> Age;
            int check5 = user->Set_Age(Age);
            while(check5!=1)
            {
                cout << "$ Age : ";
                cin >> Age;
                check5 = user->Set_Age(Age);
            }
            cout << endl ;
            
            cout << "$ Phone number : ";
            cin >> Phone_Number;
            int check4 ;
            check4 = user->Set_Phone(Phone_Number);
            while (check4 != 1)
            {
                cout << "$ Phone number : ";
                cin >> Phone_Number;
                check4 = user->Set_Phone(Phone_Number);
            }
            cout << endl ;
            
            cout << "$ Country : ";
            cin.ignore();
            getline(cin,Country);
            int check6 ;
            check6 = user->Set_Country(Country);
            while (check6 != 1)
            {
                cout << "$ Country : ";
                cin >> Country;
                check6 = user->Set_Country(Country);
            }
            cout << endl ;
        
            cout << "$ Link : ";
            getline(cin,Link);
            int check7 ;
            check7 = user->Set_Link(Link);
            while (check7 != 1)
            {
                cout << "$ Link : ";
                cin >> Link;
                check7 = user->Set_Link(Link);
            }
            cout << endl ;
            
            cout << "$ Bio : ";
            getline(cin,Bio);
            int check2 ;
            check2 = user->Set_Bio(Bio);
            while (check2 != 1)
            {
                cout << "$ Bio : ";
                cin >> Bio;
                check2 = user->Set_Bio(Bio);
            }
            cout << endl ;
            
            cout << "$ Password : ";
            cin >> Password ;
            int ckeck3 ;
            ckeck3 = user->Set_Password(Password);
            while(ckeck3 > 0)
            {
                cout << "$ Password : ";
                cin >> Password ;
                ckeck3 = user->Set_Password(Password);
            }
            cout << endl ;
            
            if(musers.count(User) == 0) // check to not have repeated username
            { 
            musers[user->Get_User()] = user;
            cout << "* You have successfully signed up.\n\n" ;
                {
                    temp = user->Get_User() ;
                    checkin = 1 ;
                    cin.ignore() ;
                    choice_login();
                    //---------------
                    //login(vec1);
                    exit(0);
                }
            }
            
            else
            {
                cout<<"! this user name has allredy exist.\n" ;
                cin.ignore();
                menu();
            }
        }
//-------------------------------------------------------
        else if (choice_s == "1")
        {
            string manager;
            cout << "$ Enter username of manager: ";
            cin >> manager;
            cin.ignore();
            
            if(musers.count(manager) == 1)
            {
                user = new Company;
                cout << "* We found this username. \n";

                if(vec1.size()==1)
                {
                    cout << "\n$ Username : ";
                    cin >> User;
                    ckeck_id(User);
                    int check1 = user->Set_User(User);
                    while (check1 > 0)
                    {
                        cout << "$ Username : ";
                        cin >> User;
                        check1 = user->Set_User(User);
                    }
                    cout << endl ;

                }
                else
                {
                    User=vec1[1];
                    ckeck_id(User);
                    int check1 = user->Set_User(User);
                    while (check1 > 0)
                    {
                        check1 = user->Set_User(User);
                    }
                    cout << endl ;
                }

                cout << "$ Name : ";
                cin >> Name;
                user->Set_Name(Name) ;
                cout << endl ;
                
                cout << "$ Phone number : ";
                cin >> Phone_Number;
                int check4 ;
                check4 = user->Set_Phone(Phone_Number);
                while (check4 != 1)
                {
                    cout << "$ Phone number : ";
                    cin >> Phone_Number;
                    check4 = user->Set_Phone(Phone_Number);
                }
                cout << endl ;
                
                cout << "$ Country : ";
                cin.ignore();
                getline(cin,Country);
                int check6 ;
                check6 = user->Set_Country(Country);
                while (check6 != 1)
                {
                    cout << "$ Country : ";
                    cin >> Country;
                    check6 = user->Set_Country(Country);
                }
                cout << endl ;
            
                cout << "$ Link : ";
                getline(cin,Link);
                int check7 ;
                check7 = user->Set_Link(Link);
                while (check7 != 1)
                {
                    cout << "$ Link : ";
                    cin >> Link;
                    check7 = user->Set_Link(Link);
                }
                cout << endl ;
                
                cout << "$ Bio : ";
                getline(cin,Bio);
                int check2 ;
                check2 = user->Set_Bio(Bio);
                while (check2 != 1)
                {
                    cout << "$ Bio : ";
                    cin >> Bio;
                    check2 = user->Set_Bio(Bio);
                }
                cout << endl ;
                
                cout << "$ Password : ";
                cin >> Password ;
                int ckeck3 ;
                ckeck3 = user->Set_Password(Password);
                while(ckeck3 > 0)
                {
                    cout << "$ Password : ";
                    cin >> Password ;
                    ckeck3 = user->Set_Password(Password);
                }
                cout << endl ;
                
                if(musers.count(User) == 0) // check to not have repeated username
                { 
                    musers[user->Get_User()] = user;
                    cout << "* You have successfully signed up.\n\n" ;
                    {
                            temp = user->Get_User() ;
                            checkin = 1 ;
                            cin.ignore() ;
                            choice_login();
                            
                    }
                }

              }  
              else
              {
                cout << "! There is no user with this username.\n";
              }
        }                
//----------------------------------------------
        else if (choice_s == "3")
        {
            save = "anonymous";
            user = new Anonymous;
            if(vec1.size()==1)
            {
                cout << "\n$ Username : ";
                cin >> User;
                ckeck_id(User);
                int check1 = user->Set_User(User);
                while (check1 > 0)
                {
                    cout << "$ Username : ";
                    cin >> User;
                    check1 = user->Set_User(User);
                }
                cout << endl ;

            }
            else
            {
                User=vec1[1];
                ckeck_id(User);
                int check1 = user->Set_User(User);
                while (check1 > 0)
                {
                    check1 = user->Set_User(User);
                }
                cout << endl ;
            }
            
            user->Set_Name("Anonymous User");
            cout << endl ;
            
            cout << "$ Password : ";
            cin >> Password ;
            int ckeck3 ;
            ckeck3 = user->Set_Password(Password);
            while(ckeck3 > 0)
            {
                cout << "$ Password : ";
                cin >> Password ;
                ckeck3 = user->Set_Password(Password);
            }
            cout << endl ;
            
            if(musers.count(User) == 0) // check to not have repeated username
            { 
            musers[user->Get_User()] = user;
            cout << "* You have successfully signed up.\n\n" ;
                {
                    temp = user->Get_User() ;
                    checkin = 1 ;
                    cin.ignore() ;
                    choice_login();
                    //---------------
                    //login(vec1);
                }
            }
            
            else
            {
                cout<<"! this user name has allredy exist.\n" ;
                cin.ignore();
                menu();
            }
        }
}
                    


//****************************************************************************************************************************
void Twitterak::login(vector<string>&vec2)//using hash for safety
{
    if(vec2.size()==1)
    {
        string username ;
        string password ;
        int c = 1 ;

        while (c!=0)
        {
        
        cout << "\n$ Username: ";
        cin >> username;
        ckeck_id(username);
        
        cout << "\n$ password: ";
        cin >> password;
        hash<string>mystd;
        
        if(musers.count(username) == 1)//login
        {
            if(musers[username]->Get_Password() == mystd(password) )//hash the password
            {
                temp = username ;
                checkin = 1 ;
                cout << "* You have successfully logged in.\n";
                c = 0 ;
                cin.ignore();
                choice_login();
            }
            else
            {
                cout << "! Your password is incorect.\n";
                
            }

        }
        else
        {
            cout << "! This Username is not found.\n";
            
        }
        
        }

    }
    else if(vec2.size()==2)
    {
            string username=vec2[1] ;
            string password ;
            int c = 1 ;

            while (c!=0)
            {
            
                ckeck_id(username);
                
                cout << "\n$ password: ";
                cin >> password;
                hash<string>mystd;
                
                if(musers.count(username) == 1) //login
                {
                    if(musers[username]->Get_Password() == mystd(password) ) //hash the password
                    {
                        temp = username ;
                        checkin = 1 ;
                        cout << "* You have successfully logged in.\n";
                        c = 0 ;
                        cin.ignore();
                        choice_login();
                    }
                    else
                    {
                        cout << "! Your password is incorect.\n";
                        
                    }

                }
                else
                {
                    cout << "! This Username is not found.\n";
                    cout << "$ Username: " ;
                    cin >> username ;
    
                }
        }

    }
    else if(vec2.size()==3)
    {
            string username=vec2[1] ;
            string password=vec2[2] ;
            int c=1 ;

            while (c!=0)
            {
                ckeck_id(username);
                hash<string>mystd;

                if(musers.count(username) == 1) //login
                {
                    if(musers[username]->Get_Password() == mystd(password) ) //hash the password
                    {
                        temp = username ;
                        checkin = 1 ;
                        cout << "* You have successfully logged in.\n";
                        c = 0 ;
                        choice_login();
                    }
                    else
                    {
                        cout << "! Your password is incorect.\n";
                        cout << "$ password: " ;
                        cin >> password ;
                    }

                }
                else
                {
                    cout << "! This Username is not found.\n";
                    cout << "$ Username: " ;
                    cin >> username ;
                    
                }
            }
    }
}
//*********************************************************************************************************************************************************

void Twitterak::logout()
{
    checkin = 0;
    cout << "* You successfully logged out.\n" ;
}

//*********************************************************************************************************************************************************
void Twitterak::choice_login() //Showing diffrent oprtions after login
{
    vector <string> vec;
    string choice2 , tweet;
    string t; //string that we use to separate words from each other(words between space)
    string checkname="likes";
    bool flag = true;
   
    while(flag == true)
    {
        if(musers.count(temp) == 1)
        {
            cout << "> @" << temp;
        }
        cout << "> " ;
        getline(cin ,choice2);
        for (int i = 0 ; i < choice2.size() ; i++)
        {
            choice2[i] = tolower(choice2[i]);
        }
        check_space(choice2) ;
        stringstream word(choice2);
        while (getline(word , t , ' '))
        {
            vec.push_back(t);
        }
        
        for (int i = 0 ; i < choice2.size() ; i++)
        {
            choice2[i] = tolower(choice2[i]);
        }
        
        size_t chec=vec[0].find(checkname) ;
        
        if(vec[0] == "logout")
        {
            logout();
            flag = false;
            menu() ;
        }
        
        else if(vec[0] == "edit" && vec[1] == "profile") 
        {
    
            string str_edit1 ,str_edit2;
            str_edit1=vec[2] ;
            str_edit2=vec[3] ;

            edit_profile(str_edit1 ,str_edit2);
        }
        
        else if(vec[0] == "tweet")
        {

            for (int i = 1; i < vec.size() ; i++)
            {
                tweet += vec[i] + " " ;
            }
            
            Tweet new1; //new object from Tweet
            
            new1.Set_date();
            check_space(tweet) ;
            new1.Set_Tweet(tweet);
            musers[temp]->set_index();
            new1.set_number(musers[temp]->get_index());

            musers[temp]->push_tweet(new1);
            
            choice_login() ;
    
        }
       
        else if(vec[0]=="retweet")
        {
            string sme2=vec[1] ; // A string for checking ":" and "@" and...
             if(sme2.find(':') != string :: npos)
            {
                ckeck_id(sme2);
                string numbers = "";
                string characters = "";
                seperator(sme2 , characters , numbers);//seprate username from tweet number 

                int m = stoi(numbers) ; //convert string into integer

                if(musers.count(characters) == 1)
                {
                    string temp2 = musers[characters]->backstring(m) ;
                    Tweet new2;
                    new2.Set_date();
                    //check_space(tweet) ;
                    new2.Set_Tweet(temp2);
                    musers[temp]->set_index();
                    new2.set_number(musers[temp]->get_index());
                    musers[temp]->push_tweet(new2);
                    choice_login() ;
                }
                else
                {
                    cout<< "! Tweet has not found.\n" ;
                }
            }
        }
       
        else if(vec[0] == "show" && vec[1] =="tweet")
        {
            string sme; //string for using in function
            sme = vec[2];
            if (sme == "@me")
            {
                musers[temp]->get_tweet();
                choice_login() ;
            }

            else if(sme.find(':') != string :: npos)
            {
                ckeck_id(sme);
                string numbers = "";
                string characters = "";
                seperator(sme , characters , numbers);//seprate username from tweet number 

                int n = stoi(numbers) ;
                
                if(musers.count(characters) == 1)//checking this character exist
                {   
                    
                   musers[characters]->get_tweet1(n);
                   tweet_object.show_numberlikes( musers[characters], n);
                   
                   choice_login() ;
                }
                else
                {
                    cout << "! We can not find this member.\n";
                    choice_login() ;
                }
                    
            }
            else
            {
                ckeck_id(sme);//ckeck the reserved word and @
                if(musers.count(sme) == 1)
                {
                   musers[sme]->get_tweet();
                   choice_login() ;
                }
                else
                {
                    cout << "! We can not find this member.\n";
                    choice_login() ;
                }
                
            }

        }
        
        else if(vec[0] == "edit" && vec[1]== "tweet")
        {
            
            int edit_tw = stoi(vec[2]);
            musers[temp]->edit_tweet(edit_tw) ;
        
        
            choice_login() ;

        }
       
        else if(vec[0] == "delete" && vec[1]== "tweet")
        {
            if (save == "personal" || save == "organisation")
            {
            int delete_tw=stoi(vec[2]) ;
            musers[temp]->delete_tweet(delete_tw) ;
            }
            else
            {
                cout << "! This account is not allowed to delete tweet.\n";
            }
            choice_login();
        }
        
        else if(vec[0]=="like")
        {
            string str = vec[1];
            ckeck_id(str);
            string numbers = "";
            string characters = "";

            seperator(str , characters , numbers);

            int num = stoi(numbers) ;
            
            
            if(musers.count(characters) == 1)//checking this character exist
            {   
               tweet_object.likes( user, musers[characters], num);
            
               choice_login() ;
            }    
        }
        
        else if (chec !=string :: npos )
        {
            string str_like = vec[0];
            ckeck_id(str_like);
            string numbers = "";
            string characters = "";
            
            seperator(str_like , characters , numbers);

            int num = stoi(numbers) ;
            
            if(musers.count(characters) == 1) //checking this character exist
            {   
               tweet_object.show_likers(musers[characters], num);
               tweet_object.show_numberlikes( musers[characters], num);
               choice_login() ;

            }    
        }
        
        else if(vec[0]=="dislike")
        {
            string str_dis = vec[1];
            ckeck_id(str_dis);
            string numbers = "";
            string characters = "";
            

            seperator(str_dis , characters , numbers);

            int num = stoi(numbers) ;
            
            
            if(musers.count(characters) == 1)
            {   
               tweet_object.dislike( user, musers[characters], num);
               tweet_object.show_numberlikes( musers[characters], num);
               choice_login() ;
            }    
        }

        else if(vec[0]=="follow")
        {
            string strf = vec[1];
            ckeck_id(strf);
            
            if(musers.count(strf) == 1)//checking this character exist
            { 
                musers[temp]->add_following(strf) ;
                musers[strf]->increase_follower() ;
                choice_login() ;
            }
            else
            {
                cout << "! Can not find this account.\n" ;
                choice_login() ;
            }    
        }
        
        else if(vec[0]=="show")
        {
            string profile = vec[1] ;
            show(profile);
        }
        
        else if(vec[0]=="delete" && vec[1]=="account")
        {
            delete_account();
             flag = false;
             menu() ;
        }
       
        else if(vec[0] == "exit" || vec[0]=="q" || vec[0]=="quit")
        {
            char ask;
            cout << "? Are you sure?(y/n) : ";
            cin >> ask;
            if (ask == 'y')
            {
                cout << "* Good Bye.";
                exit(0);
            }
            else
            {
                menu() ;

            }
        }
        
        else
        {
            cout << "! login Undefined command.\n" ;
            choice_login() ;
            
        }
    }
 }
 //********************************************************************************************************************************************************
void Twitterak::delete_account()
    {
        cout << "? Are you sure that you want to delete your account(y/n) ?" ;
        string ch ;
        getline(cin ,ch) ;
        if(ch[0]=='y')
        {
            musers.erase(temp) ;
            logout() ;
            cout << "* Your account has been deleted.\n" ;
        } 
        else
        {
          choice_login() ;
        }
    }

//************************************************************************************************************************************************************
void Twitterak:: edit_profile(string edit ,string changable)
    {
        system("Color 0F");
        
        cout << "> ";
        
        if(musers.count(temp)==1)
        {
            if(edit == "name")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                musers[temp]->Set_Name(changable) ;
                cout << "* Your name has been successfully changed.\n" ;
                choice_login();
            }

            else if(edit == "age")
            {
                musers[temp]->Set_Age(changable) ;
                cout << "* Your age has been successfully changed.\n" ;
                choice_login();
            }

            else if(edit == "phone number")
            {
                musers[temp]->Set_Phone(changable) ;
                cout << "* Your phone number has been successfully changed.\n" ;
                choice_login();
            }

            else if(edit == "country")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                musers[temp]->Set_Country(changable) ;
                cout << "* Your country has been successfully changed.\n" ;
                choice_login();
            }

            else if(edit == "link")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                musers[temp]->Set_Link(changable) ;
                cout << "* Your link has been successfully changed.\n" ;
                choice_login();
            }
            else if(edit == "bio")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                musers[temp]->Set_Bio(changable) ;
                cout << "* Your bio has been successfully changed.\n" ;
                choice_login();
            }
            
            else if(edit == "password")//final change!!!!!!!!!
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                hash<string>mystd;
                if(musers[temp]->Get_Password() == mystd(changable))
                {
                    cout << "! Registration failed.\n" ;
                }
                else
                {
                    musers[temp]->Set_Password(changable) ;
                    cout << "* Your password has been successfully changed.\n" ;

                }
                choice_login();
            }
            
            else if(edit == "username")
            {
                changable.erase(0, 1);
                changable.erase(changable.size() - 1 , 1);
                ckeck_id(changable);
                musers[temp]->Set_User(changable) ;
                Common *temp2 = musers[temp];
                musers.erase(temp) ;
                musers[temp2->Get_User()] = temp2 ;
                temp = temp2->Get_User() ;
                cout << "* Your user name has been successfully changed.\n" ;
                choice_login();
            }

            else if(edit == "header")
            {
            
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                color = changable;
                musers[temp]->Set_Header(color) ;
                header(color);
                choice_login();
            
            }
            else
            {
                cout << "! edit undefined command.\n" ;
            }
        }
    }
//*************************************************************************************************************************************************************

void Twitterak::show(string profile)
    {
       
        ckeck_id(profile);
    
        if(profile=="me" || profile=="profile")
        {

            if(musers.count(temp) == 1){

            musers[temp]->Get_Header();
            header(color);
            musers[temp]->profile_me();
            choice_login() ;
            }
        }
       
        else if(musers.count(profile)==1)
        {
            musers[profile]->Get_Header();
            header(color);
            musers[profile]->profile_other();
            choice_login() ;
        }
        else
        {
            cout << "!we can not find this member.\n" ;
            choice_login() ;
        }
        

    }
    
//*****************************************************************************************************************