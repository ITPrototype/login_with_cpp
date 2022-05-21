#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void login();
void registr();
void forgot();

int main(){
    system("cls");
    int choice;
    cout<<" ******************* Login ******************* \n";
    cout<<"1.Login";
    cout<<"\n2.Register";
    cout<<"\n3.Forgot password";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"Thanks for using the login page\n";
            break;
        default:
            cout<<"Sorry, wrong choice!\n";
            main();
    }
}
void registr(){
    string reguser,regpass;
    system("cls");
    cout<<"Enter the username:";
    cin>>reguser;
    cout<<"Enter the password: ";
    cin>>regpass;
    
    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"You registered successfully!\n";
    main();
}
void login(){
    int exist;
    string user,pass,u,p;
    system("cls");
    cout<<"Enter the username: ";
    cin>>user;
    cout<<"Enter the password: ";
    cin>>pass;

    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u == user && p == pass)
        {
            exist = 1;
        }
    }
    input.close();
    if(exist == 1)
    {
        system("cls");
        cout<<"********************************************\n";
        cout<<"\t\t   Welcome "<<user<<"\n\t\tHow are you bitch?\n";
        cout<<"********************************************\n";
        cout<<' '<<endl;
        cout<<"press => [[Enter]] to continue!\n";
        cin.get();
        cin.get();
        main();
    }
    else{
        cout<<"***********************************************\n\n";
        cout<<"\t\t    Login error\n\t\tWrong password bitch!\n\n";
        cout<<"***********************************************\n\n";
        cout<<' '<<endl;
        cout<<"press => [[Enter]] to continue!\n";
        cin.get();
        cin.get();
        main();
    }
}
void forgot()
{
    int ch;
    system("cls");
    cout<<"1.Search your account by username\n";
    cout<<"2.Search your account by password\n";
    cout<<"3.MainMenu\n";
    cout<<"Enter your choice:";
    cin>>ch;
    
    switch(ch){
        case 1:
           { int ex = 0;
            string searchForUser,searus,searpas;
            cout<<"Enter your remembered username: ";
            cin>>searchForUser;

            ifstream input("database.txt");
            while(input>>searus>>searpas)
            {
                if(searus == searchForUser)
                {
                    ex = 1;
                    break;
                }
            }
            input.close();
            if(ex == 1)
            {
                cout<<"Your account found!\n";
                cout<<"Your password is: "<<searpas<<endl<<endl<<"press => [[Enter]] to continue!\n";
                cin.get();
                cin.get();
                main();
            }
            else
            {
                cout<<"Sorry cannot found by your username!\n"<<endl;
                cin.get();
                cin.get();
                cout<<"press => [[Enter]] to continue!\n";
                main();
            }
            break;
        }
        case 2:
        {
            int exis = 0;
            string searchForPass,searchWuser,searchWpass;
            system("cls");
            cout<<"Enter last remembered password: ";
            cin>>searchForPass;
            ifstream input("database.txt");
            while(input>>searchWuser>>searchWpass)
            {
                if(searchWpass == searchForPass)
                {
                    exis = 1;
                    break;
                }
            }
            input.close();
            if(exis == 1)
            {
                cout<<"Your account found!\n";
                cout<<"Your account is: "<<searchWuser<<endl;
                cout<<"Your password is: "<<searchWpass<<endl<<endl<<"press => [[Enter]] to continue!\n";
                cout<<' '<<endl;
                cin.get();
                cin.get();
                main();
            }
            else
            {
                cout<<"Sorry cannot found by your password!\n"<<endl<<endl<<"press => [[Enter]] to continue!\n";
                cin.get();
                cin.get();
                main();
            }
            break;
        }
        case 3:
        {
            main();
            break;
        }
    }
}
