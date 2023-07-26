#include <iostream>
#include <unordered_map>
#include <string>
#include "users.h"
#include "twitterak.h"
#include <bitset>
#include <functional>
#include <vector>
#include <sstream>


using namespace std ;

//objects of classes
Personal* per = nullptr;
Company* comp = nullptr;
Anonymous* ano = nullptr;

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
    per = new Personal;
    comp = new Company;
    ano = new Anonymous;


    bool flag = true;
    string choice_s;
    
    // while(flag == true)
        //========
        cout << "    > organisation\n    > personal\n    > anonymous\n> ";
        //=========
        getline(cin ,choice_s);
        for (int i = 0 ; i < choice_s.size() ; i++)
        {
            choice_s[i] = tolower(choice_s[i]);
        }
        
        if (choice_s == "personal")
        {
            save = "personal";
            if(vec1.size()==1)
            {
                cout << "\n$ Username : ";
                cin >> User;
                ckeck_id(User);
                int check1 = per->Set_User(User);
                while (check1 > 0)
                {
                    cout << "$ Username : ";
                    cin >> User;
                    check1 = per->Set_User(User);
                }
                cout << endl ;

            }
            else
            {
                User=vec1[1];
                ckeck_id(User);
                int check1 = per->Set_User(User);
                while (check1 > 0)
                {
                    check1 = per->Set_User(User);
                }
                cout << endl ;
            }

            cout << "$ Name : ";
            cin >> Name;
            per->Set_Name(Name) ;
            cout << endl ;
            
            cout << "$ Age : ";
            cin >> Age;
            int check5 = per->Set_Age(Age);
            while(check5!=1)
            {
                cout << "$ Age : ";
                cin >> Age;
                check5 = per->Set_Age(Age);
            }
            cout << endl ;
            
            cout << "$ Phone number : ";
            cin >> Phone_Number;
            int check4 ;
            check4 = per->Set_Phone_p(Phone_Number);
            while (check4 != 1)
            {
                cout << "$ Phone number : ";
                cin >> Phone_Number;
                check4 = per->Set_Phone_p(Phone_Number);
            }
            cout << endl ;
            
            cout << "$ Country : ";
            cin.ignore();
            getline(cin,Country);
            int check6 ;
            check6 = per->Set_Country_p(Country);
            while (check6 != 1)
            {
                cout << "$ Country : ";
                cin >> Country;
                check6 = per->Set_Country_p(Country);
            }
            cout << endl ;
        
            cout << "$ Link : ";
            getline(cin,Link);
            int check7 ;
            check7 = per->Set_Link_p(Link);
            while (check7 != 1)
            {
                cout << "$ Link : ";
                cin >> Link;
                check7 = per->Set_Link_p(Link);
            }
            cout << endl ;
            
            cout << "$ Bio : ";
            getline(cin,Bio);
            int check2 ;
            check2 = per->Set_Bio_p(Bio);
            while (check2 != 1)
            {
                cout << "$ Bio : ";
                cin >> Bio;
                check2 = per->Set_Bio_p(Bio);
            }
            cout << endl ;
            
            cout << "$ Password : ";
            cin >> Password ;
            int ckeck3 ;
            ckeck3 = per->Set_Password(Password);
            while(ckeck3 > 0)
            {
                cout << "$ Password : ";
                cin >> Password ;
                ckeck3 = per->Set_Password(Password);
            }
            cout << endl ;
            
            if(mpersonal.count(User) == 0) // check to not have repeated username
            { 
            mpersonal[per->Get_User()] = per;
            cout << "* You have successfully signed up.\n\n" ;
                {
                    temp = per->Get_User() ;
                    checkin = 1 ;
                    cin.ignore() ;
                    //choice_login();
                    //---------------
                    login(vec1);
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
        else if (choice_s == "organisation")
        {
            save = "organisation";
            if(vec1.size()==1)
            {
                cout << "\n$ Username : ";
                cin >> User;
                ckeck_id(User);
                int check1 = comp->Set_User(User);
                while (check1 > 0)
                {
                    cout << "$ Username : ";
                    cin >> User;
                    check1 = comp->Set_User(User);
                }
                cout << endl ;

            }
            else
            {
                User=vec1[1];
                ckeck_id(User);
                int check1 = comp->Set_User(User);
                while (check1 > 0)
                {
                    check1 = comp->Set_User(User);
                }
                cout << endl ;
            }

            cout << "$ Name : ";
            cin >> Name;
            comp->Set_Name(Name) ;
            cout << endl ;
            
            cout << "$ Phone number : ";
            cin >> Phone_Number;
            int check4 ;
            check4 = comp->Set_Phone_c(Phone_Number);
            while (check4 != 1)
            {
                cout << "$ Phone number : ";
                cin >> Phone_Number;
                check4 = comp->Set_Phone_c(Phone_Number);
            }
            cout << endl ;
            
            cout << "$ Country : ";
            cin.ignore();
            getline(cin,Country);
            int check6 ;
            check6 = comp->Set_Country_c(Country);
            while (check6 != 1)
            {
                cout << "$ Country : ";
                cin >> Country;
                check6 = comp->Set_Country_c(Country);
            }
            cout << endl ;
        
            cout << "$ Link : ";
            getline(cin,Link);
            int check7 ;
            check7 = comp->Set_Link_c(Link);
            while (check7 != 1)
            {
                cout << "$ Link : ";
                cin >> Link;
                check7 = comp->Set_Link_c(Link);
            }
            cout << endl ;
            
            cout << "$ Bio : ";
            getline(cin,Bio);
            int check2 ;
            check2 = comp->Set_Bio_c(Bio);
            while (check2 != 1)
            {
                cout << "$ Bio : ";
                cin >> Bio;
                check2 = comp->Set_Bio_c(Bio);
            }
            cout << endl ;
            
            cout << "$ Password : ";
            cin >> Password ;
            int ckeck3 ;
            ckeck3 = comp->Set_Password(Password);
            while(ckeck3 > 0)
            {
                cout << "$ Password : ";
                cin >> Password ;
                ckeck3 = comp->Set_Password(Password);
            }
            cout << endl ;
            
            if(mcompany.count(User) == 0) // check to not have repeated username
            { 
            mcompany[comp->Get_User()] = comp;
            cout << "* You have successfully signed up.\n\n" ;
                {
                    temp = comp->Get_User() ;
                    checkin = 1 ;
                    cin.ignore() ;
                    //choice_login();
                    //---------------
                    login(vec1);
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

//----------------------------------------------
        else if (choice_s == "anonymous")
        {
            save = "anonymous";
            if(vec1.size()==1)
            {
                cout << "\n$ Username : ";
                cin >> User;
                ckeck_id(User);
                int check1 = ano->Set_User(User);
                while (check1 > 0)
                {
                    cout << "$ Username : ";
                    cin >> User;
                    check1 = ano->Set_User(User);
                }
                cout << endl ;

            }
            else
            {
                User=vec1[1];
                ckeck_id(User);
                int check1 = ano->Set_User(User);
                while (check1 > 0)
                {
                    check1 = ano->Set_User(User);
                }
                cout << endl ;
            }
            
            ano->Set_Name("Anonymous User");
            cout << endl ;
            
            cout << "$ Password : ";
            cin >> Password ;
            int ckeck3 ;
            ckeck3 = ano->Set_Password(Password);
            while(ckeck3 > 0)
            {
                cout << "$ Password : ";
                cin >> Password ;
                ckeck3 = ano->Set_Password(Password);
            }
            cout << endl ;
            
            if(manonymous.count(User) == 0) // check to not have repeated username
            { 
            manonymous[ano->Get_User()] = ano;
            cout << "* You have successfully signed up.\n\n" ;
                {
                    temp = ano->Get_User() ;
                    checkin = 1 ;
                    cin.ignore() ;
                    //choice_login();
                    //---------------
                    login(vec1);
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
}
                    

//*********************************************************************************************************************************************************

void Twitterak::menu()
{
    // welcome printing
    
    // system("Color 01");
    // cout << "W       O\n" ;
    // cout << "  E   C   M    to  | T | W | I | T | T | E | R | A | K |\n" ;
    // cout << "    L       E\n" ;
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
        // else if(vec1[0] == "login")
        // {
        //     login(vec1);
        //}
        if(vec1[0] == "signup" )
        {
            signup(vec1);
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

//****************************************************************************************************************************
void Twitterak::login(vector<string>&vec2)//using hash for safety
{
    //personal login
    if(save == "personal")
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
            
            if(mpersonal.count(username) == 1)//login
            {
                if(mpersonal[username]->Get_Password() == mystd(password) )//hash the password
                {
                    temp = username ;
                    checkin = 1 ;
                    cout << "* You have successfully logged in.\n";
                    c = 0 ;
                    cin.ignore();
                    //choice_login();
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
                    
                    if(mpersonal.count(username) == 1) //login
                    {
                        if(mpersonal[username]->Get_Password() == mystd(password) ) //hash the password
                        {
                            temp = username ;
                            checkin = 1 ;
                            cout << "* You have successfully logged in.\n";
                            c = 0 ;
                            cin.ignore();
                            //choice_login();
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

                    if(mpersonal.count(username) == 1) //login
                    {
                        if(mpersonal[username]->Get_Password() == mystd(password) ) //hash the password
                        {
                            temp = username ;
                            checkin = 1 ;
                            cout << "* You have successfully logged in.\n";
                            c = 0 ;
                            //choice_login();
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
    //---------------------------------------------------------------------
    //anonymous login

    else if (save == "anonymous")
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
            
            if(manonymous.count(username) == 1)//login
            {
                if(manonymous[username]->Get_Password() == mystd(password) )//hash the password
                {
                    temp = username ;
                    checkin = 1 ;
                    cout << "* You have successfully logged in.\n";
                    c = 0 ;
                    cin.ignore();
                    //choice_login();
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
                    
                    if(manonymous.count(username) == 1) //login
                    {
                        if(manonymous[username]->Get_Password() == mystd(password) ) //hash the password
                        {
                            temp = username ;
                            checkin = 1 ;
                            cout << "* You have successfully logged in.\n";
                            c = 0 ;
                            cin.ignore();
                            //choice_login();
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

                    if(manonymous.count(username) == 1) //login
                    {
                        if(manonymous[username]->Get_Password() == mystd(password) ) //hash the password
                        {
                            temp = username ;
                            checkin = 1 ;
                            cout << "* You have successfully logged in.\n";
                            c = 0 ;
                            //choice_login();
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
//---------------------------------------------------------------------
//company login
    else if(save == "organisation")
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
            
            if(mcompany.count(username) == 1)//login
            {
                if(mcompany[username]->Get_Password() == mystd(password) )//hash the password
                {
                    temp = username ;
                    checkin = 1 ;
                    cout << "* You have successfully logged in.\n";
                    c = 0 ;
                    cin.ignore();
                    //choice_login();
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
                    
                    if(mcompany.count(username) == 1) //login
                    {
                        if(mcompany[username]->Get_Password() == mystd(password) ) //hash the password
                        {
                            temp = username ;
                            checkin = 1 ;
                            cout << "* You have successfully logged in.\n";
                            c = 0 ;
                            cin.ignore();
                            //choice_login();
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

                    if(mcompany.count(username) == 1) //login
                    {
                        if(mcompany[username]->Get_Password() == mystd(password) ) //hash the password
                        {
                            temp = username ;
                            checkin = 1 ;
                            cout << "* You have successfully logged in.\n";
                            c = 0 ;
                            //choice_login();
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
}
