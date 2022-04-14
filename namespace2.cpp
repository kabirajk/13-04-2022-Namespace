#include <iostream>
// using namespace std;

namespace SignUp
{   //class that holds the data of profile

    class Proflie
    {      
        std::string nickname;
        std::string id_number;
        Proflie(std::string Nick_name,std::string idnumber)
        {   
            nickname=Nick_name;
            id_number=idnumber;
        }
        friend int Createaccount();
        friend Proflie* fillprofile();
        // friend class Account;
        public:
        void print()//function to print data
        {
            std::cout<<"\"Nick name\" [ "<<nickname<<" ] , \"Id\"  [ "<<id_number<<" ]\n";
        }
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
        // public:
        void get_profile()
        {   Id_profile->print();
            // std::cout<<Id_profile->id_number;//if class is accessible
        }
    };
   
   
    //credlist anonymous class object tht holds the details of credentials 
    class 
    {
        // Acc_list[]//ptr;
        Account * list[10];
        int account_index=0;

        friend int Createaccount();
        friend Proflie* fillprofile();
        friend int login();
        friend void show_profile(int list_id);
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
       // Proflie * my=fillprofile();    std::cout<<my->nickname;// std::cout<<cred_list.list[cred_list.account_index]->Id_profile->id_number;
        std::cout<<(cred_list.list[cred_list.account_index]->Id_profile==nullptr ? "profile not complitted\n":"completed\n");
        // std::cout<<cred_list.list[cred_list.account_index]->Id_profile->id_number;
        
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
            return i;
        }
        else
        {
            std::cout<<"cred not correct\n";
            return 0;
        }
    return 0;
    }

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
            {
               SignUp::login();
               //make namespaces for login to show & set data

            }
    }
    
    return 0;
}
