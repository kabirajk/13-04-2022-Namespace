#include <iostream>
// using namespace std;

namespace SignUp
{   //class that holds the data of profile

    class Proflie
    {      
        std::string nickname="None";
        std::string id_number="None";
        Proflie()
        {

        }
        Proflie(std::string Nick_name,std::string idnumber)
        {   
            nickname=Nick_name;
            id_number=idnumber;
        }
        friend int Createaccount();
        friend Proflie* fillprofile();
        friend int logged_in(int account_id);

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
        std::string username="None";
        std::string password="None";
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
        friend int logged_in(int account_id);
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
        Account * list[10]={0};
        int account_index=0;

        friend int Createaccount();
        friend Proflie* fillprofile();
        friend int login();
        friend void show_profile(int list_id);
        friend int logged_in(int account_id);
    }cred_list;

    //function responsibe for filling profile
    Proflie* fillprofile()
    {   std::string nickname="None",id_number="None";
        std::cout<<"enter the Nick name (enter None or 0 to skip now)";
        std::cin>>nickname;
        std::cout<<"enter the user id_number(enter None or 0 to skip now) : ";
        std::cin>>id_number;
        if (id_number=="0"||nickname=="0"||id_number=="None"||nickname=="None")
                return (new Proflie());
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
        std::cout<<"enter the user name: ";
        std::cin>>Username;
        std::cout<<"enter the password: ";
        std::cin>>password;
        int i=0;
        // std::cout<<"print:"<<(cred_list.list[i]==0);

        while(i<=cred_list.account_index && cred_list.list[i]!=0)
        {
            if(cred_list.list[i]->username==Username)
                break;

            i++;
        }

        if (i==10||cred_list.list[i]==0) 
            {   std::cout<<"\r<==== username not found please create a account ====>\n";
                return 0;
            }
        else if(cred_list.list[i]->password==password)
        {
            std::cout<<"logged in\n";
            return i;
        }
        else
        {
            std::cout<<"cred not correct\n";
            return 420;
        }
    // std::cout<<"wrong Creds\n"<<Username<<"or password ***************";
    // return 0;
    }

    int logged_in(int account_id)
    {   
        if(account_id!=420 && cred_list.account_index!=0)
        while (1)
        {
            int option=1;
            std::cout<<"1 .view details 2. for edit details 3.exit: ";
            std::cin>>option;
            if (option==1)
                cred_list.list[account_id]->get_profile();
            else if(option==2)
            {   std::cout<<"to change 1.usernanme 2.id 3.both: \n";
                std::cin>>option;
                std::string value="";
                if (option==1)//for user name only
                    {   std::cout<<"enter the new nick name: ";
                        std::cin>>value;
                    cred_list.list[account_id]->Id_profile->nickname=value;
                    }
                else if (option==2)//for user name only
                    {   std::cout<<"enter the new id: ";
                        std::cin>>value;
                    cred_list.list[account_id]->Id_profile->id_number=value;
                    }
                else if(option==3)
                {  
                    std::cout<<"enter the new Nick name: ";
                    std::cin>>value;
                    cred_list.list[account_id]->Id_profile->nickname=value;

                    std::cout<<"enter the new id: ";
                    std::cin>>value;
                    cred_list.list[account_id]->Id_profile->id_number=value;
                }
            }
            else if(option==3)
                break;

        }
    return 0;
    }

}


int main()
{   
    while (1)
    {   int option=0;
        std::cout<<"1 signup\n2.login\n3.exit\n";
        std::cin>>option;
        if(option==1)
            SignUp::Createaccount();
        if(option ==2)
            {
               SignUp::logged_in(SignUp::login());//make namespaces for login to show & set data
            }
         if(option ==3)
            break;
    }
    return 0;
}
