#include<bits/stdc++.h>

using namespace std ;

class ATM
{
    private :
                int PIN = 8888 ; 
                long double balance = 50580.57 ;
                long double amount = 0 ;
                
    public :
            void graphic_H()
            {
                // Page Decoration
                cout << "\033[1;45m                                                                                                             " ;
                cout << "\n\t\t\t\t\t\t   HIMANSHU  ATM   \n" ;
                cout << "                                                                                                             " ;
                cout << "\033[0;0m \n";
            }

            void thanku()
            {
                cout << "\n\n\t\t\t\t\t THANK YOU for using HIMANSHU ATM ...\n" ;
            }

            void graphic_B()
            {
                cout << "\n\033[0;45m                                                                                                             " ;
                cout << "\033[0;0m \n\n\n ***********************************************************************************************************\n\n\n\n";
            }

            void welcome()
            {   
                graphic_H() ;
                cout << "\n\n \t\t\t\t\t\t   \033[4;37m   WELCOME   \033[0;0m\n" ;
                cout << "\n\n\n\033[3;35m\t\t\t\t\t     Please Enter your  \"PIN\" \n \033[0;0m \033[7;37m" ;
                cout << "\n\t\t\t\t\t\t-------------------" ;
                cout << "\n\t\t\t\t\t\t|  1  |  2  |  3  |" ;
                cout << "\n\t\t\t\t\t\t-------------------" ;
                cout << "\n\t\t\t\t\t\t|  4  |  5  |  6  |" ;
                cout << "\n\t\t\t\t\t\t-------------------" ;
                cout << "\n\t\t\t\t\t\t|  7  |  8  |  9  |" ;
                cout << "\n\t\t\t\t\t\t-------------------\n\n\033[0;0m" ;
                
                cout << "\n( Hint : The PIN Number is " << PIN << " )\t\t\t";

                int inputpin = 0 ;
                cin >> inputpin ;

                int count = 3 ;
                while( PIN != inputpin && count > 1 )
                {
                    cout << "\n\n\t\t\t\t    \033[7;31m INVALID PIN ! \033[0;0m Please Re-Enter The PIN \n \n\t\t\t\t\t\t\t" ;
                    cin >> inputpin ;
                                        --count ;
                    
                    if( PIN != inputpin && count == 1 )
                    {
                        cout << "\n\n \t\t\t    Number of Attempts Exceeded !  Please Try after Some Time . " ;
                        thanku();
                    } 
                }

                graphic_B() ;

                if( inputpin == PIN )
                    menu();

            } 

            void menu() 
            {
                graphic_H() ;
                cout << "\n\n\n\t\t\t\tPlease Select the Transaction Type b/w : 1 - 6 \n\n\n" ;
                cout << "\t\t\t\t\t\t\033[7;31m  1. BALANCE ENQUIRY \n\n" ;
                cout << "\t\t\t\t\t\t  2. WITHDRAWAL \n\n" ;
                cout << "\t\t\t\t\t\t  3. ADD AMOUNT \n\n" ;
                cout << "\t\t\t\t\t\t  4. CHANGE PIN \n\n" ;
                cout << "\t\t\t\t\t\t  5. MOBILE BANKING \n\n" ;
                cout << "\t\t\t\t\t\t  6. EXIT \033[0;0m\n\n\n\n\t\t\t\t\t\t\t" ;

                int choice = 0 ;
                cin >> choice ;     cout << "\n\n" ;
                
                switch( choice )
                {
                    case 1 : balance_enquiry() ; break ; 
                    case 2 : withdrawal() ; break ; 
                    case 3 : add_amount() ; break ; 
                    case 4 : change_pin() ; break ; 
                    case 5 : mobile_banking() ; break ; 
                    case 6 : exit() ; break ; 
                    default : cout << "\n\t\t\t\t\t\t INVALID OPTION !! \n\n" ;  menu() ;
                }
                graphic_B() ;
            }

            void balance_enquiry() 
            {   
                graphic_B() ;
                graphic_H() ;
                cout << "\n\n\n\n\t\t\t \033[0;32m AVAILABLE BALANCE : \n\n\n\t\t\t\t\t\t\t\033[0;0mRs.\n\n\n\n\t\t\t\t\t\t\t" ;
                cout << balance << "\n\n\n" ;

                press_exit() ;
            }

            void withdrawal()
            {
                graphic_B() ;
                graphic_H() ;
                cout << "\n\n\n\t\t\t\t\t Enter The Amount To WITHDRAW : \n\n\n\t\t\t\t\t\t\t Rs.\n\n\n\t\t\t\t\t\t\t " ;
                cin >> amount ;

                if( balance < amount )
                {
                    cout << "\n\n\n\t\t\t\t \033[7;31m Your AMOUNT EXCEEDS The ACCOUNT BALANCE ! Please TRY AGAIN ...\033[7;31m" ;
                    press_exit() ;
                }    

                else if( balance >= amount )
                {
                    balance = balance - amount ;
                    cout << "\n\n\n\n\t\t\t \033[0;32m UPDATED BALANCE : \n\n\t\t\t\t\t\t\t\033[0;0mRs.\n\n\n\t\t\t\t\t\t\t" ;
                    cout << balance << "\033[0;0m \n\n\n" ;

                    press_exit() ;
                }
            }

            void add_amount()
            {
                graphic_B() ;
                graphic_H() ;
                cout << "\n\n\n\t\t\t\t\t     Enter The Amount To ADD : \n\n\n\t\t\t\t\t\t\t Rs.\n\n\n\t\t\t\t\t\t\t " ;
                cin >> amount ;

                balance = balance + amount ;
                    cout << "\n\n\n\n\t\t\t \033[0;32m UPDATED BALANCE : \n\n\t\t\t\t\t\t\t\033[0;0mRs.\n\n\n\t\t\t\t\t\t\t" ;
                    cout << balance << "\033[0;0m \n\n\n" ;

                    press_exit() ;
            }

            void change_pin()
            {
                graphic_B() ;
                graphic_H() ;
                cout << "\n\n\n\n\033[1;31m\t\t\t\t\t     Enter The NEW PIN Number : \n\n\t\t\t\t\t\t\t" ;
                cin >> PIN ;
                cout << "\n\n\n\t\t\t\t\t  The PIN Number Has Been Updated !!! \033[0;0m \n\n" ;

                press_exit() ;
            }

            void mobile_banking()
            {
                graphic_B() ;
                graphic_H() ;
                cout << "\n\n\n\033[0;36m\t\t\t\t WELCOME to The MOBLILE_BANKING Services !!" ;
                cout << "\n\n\n\n\033[3;36m\t\t\t\t INSTRUCTION 1 :- Download the YONO Mobile Application \n\t\t\t\t\t\t    from Google Play Store . " ;
                cout << "\n\n\t\t\t\t INSTRUCTION 2 :- DO NOT SHARE YOUR OTP TO ANYBODY . \n" ;
                cout << "\n\n\t\t\t\t INSTRUCTION 3 :- In Case of Account FRAUD , \n\t\t\t\t\t\t    VISIT / CONTACT Your BANK IMMIDIATELY . \033[0;0m \n\n" ;
                
                press_exit() ;
            }

            void exit()
            { 
                thanku() ;  graphic_B() ;  welcome() ;
            }

            void press_exit()
            {
                int zero ;
                cout << "\n\n\n\t\t\t\t       \033[7;37mPress 0 to EXIT & 1 for Main Menu : " ;
                cin >> zero ;       cout << "\033[0;0m" ;

                if( zero == 0 )
                {
                    thanku() ;      graphic_B() ;       welcome() ;
                }    
                else if ( zero == 1 )
                {
                    graphic_B() ;       menu() ;
                }  
                else
                {
                    cout << "\t\t\t\t\t     wrong choice ! try again " ;
                    press_exit() ;
                }   
            }

};

int main()
{
    ATM obj ;

    obj.welcome() ;

    return 0 ;
}