#include <iostream>
// using namespace std;
namespace SignUp
{   //class that holds the data of profile
    class Proflie
    {      
        std::string nickname;
        std::string id_number;
        Proflie(std::string Nick_name,std::string id_number)
        {   
            nickname=Nick_name;
            id_number=id_number;
        }

        friend int Createaccount();
        friend Proflie* fillprofile();
    };

    //class that holds the accounts whole data
        class Account
    {
        std::string username;
        std::string password;
        //profile//ptr=
        Proflie * Id_profile=nullptr;

        Account()
        {   std::cout<<"enter the user name: ";
            std::cin>>username;
            std::cout<<"enter the user passwaord: ";
            std::cin>>password;
        }
        friend int Createaccount();
        friend int login();
    };
    //credlist anonymus class object tht holds the details of credentials 
    class 
    {
        // Acc_list[]//ptr;
        Account * list[10];
        int account_index=0;
        friend int Createaccount();
        friend Proflie* fillprofile();
        friend int login();
    }cred_list;

    //function responsibe for filling profile
    Proflie* fillprofile()
    {   std::string nickname="",id_number="";
        std::cout<<"enter the Nick name (enter None or 0 to skip now)";
        std::cin>>nickname;
        std::cout<<"enter the user id_number(enter None or 0 to skip now) : ";
        std::cin>>id_number;
        if (id_number=="0"||nickname=="0"||id_number=="None"||nickname=="None")
                return nullptr;
        return (new Proflie(nickname,id_number));
    }

    //function responsible for creating account
    int Createaccount()
    {   if(cred_list.account_index==10)
            { 
                std::cout<<"account data base filled";
                return 0;
            }
        cred_list.list[cred_list.account_index]= new Account();
        std::cout<<"account created";
        cred_list.list[cred_list.account_index]->Id_profile=fillprofile();
        std::cout<<(cred_list.list[cred_list.account_index]->Id_profile==nullptr ? "profile not complitted\n":"completed\n");
        cred_list.account_index+=1;
        return 0;
    }
    int login()
    {
        std::string Username,password;
        std::cout<<"#====== LOGIN ======#\n";
        std::cout<<"enter the user name";
        std::cin>>Username;
        std::cout<<"enter the password";
        std::cin>>password;
        int i=0;
        while(i<10 && (cred_list.list[i])->username!=Username)
            i++;
        if (i==10) return 0;
        if(cred_list.list[i]->password==password)
        {
            std::cout<<"logged in\n";
        }
        else
        {
            std::cout<<"cred not correct\n";
            return 0;
        }
    return 0;
    }

}

namespace LogIn
{ 
    

}

int main()
{   
    while (1)
    {   int option=0;
        std::cout<<"1 signup\n2.login\n";
        std::cin>>option;
        if(option==1)
            SignUp::Createaccount();
        if(option ==2)
            SignUp::login();
    }
    
    return 0;
}



// namespace No_login
// {
//     class account
//     {   
//         std::string user_name;
//         std::string password;
//         public:
//         account_profile::details* profile=nullptr;
//         account()
//         {   std::cout<<"enter the user name: ";
//             std::cin>>user_name;
//             std::cout<<"enter the user passwaord: ";
//             std::cin>>password;

//         }
//         public:
//         static account * create()
//         {
//             return new account();
//         }
//         friend void Create_account();

//         // account_profile::details* operator ->()
//         // {
//         //     return profile;
//         // }
//     };
//     void Create_account()
//     {   //pointer to pointer to class// a[i]=ptr
//         *(login_database.data+login_database.data_index)=account::create();
//         std::cout<<"account created\n";
//        // login_database.data[login_database.data_index]-> profile = account_profile::new details();
//        (login_database.data[login_database.data_index])->profile;
       
//         //*(*(login_database.data+login_database.data_index))->profile=nullptr;
        
//         login_database.data_index+=1;
//     }
//     class 
//     {   public:
//         account* data[10];
//         int data_index=0;
//         public:
//         friend void Create_account();
//     }
//     login_database;
// }

// namespace account_profile
// {
//     class details
//     {   
//         public:
//         details()
//         {

//         }
//         friend  void  No_login::Create_account();
//     };
// }