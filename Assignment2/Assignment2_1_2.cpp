#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:

        void initDate(){
            day = 1;
            month = 1;
            year = 2000;
        }

        void isLeapYear(){
            if (((year%4)==0 && (year%100!=0)) || ((year%4)==0 && (year%400==0))){
                cout<<"Year is Leap Year"<<endl;
            }
            else{
                cout<<"Year is not a Leap Year"<<endl;
            }
        }

        void acceptDateFromConsole(){
            cout<<"Enter the day:- "<<endl;
            cin>>day;

            cout<<"Enter the month:- "<<endl;
            cin>>month;

            cout<<"Enter the year:- "<<endl;
            cin>>year;
        }

        void printDateOnConsole(){
            cout<<"The date is:- "<<day<<"/"<<month<<"/"<<year<<endl;
        }
};

int menu(){
    int choice;
    cout<<"0. Exit from the system!!!"<<endl;
    cout<<"1. Print date on Console!!!"<<endl;
    cout<<"2. Accept Date from Console!!!"<<endl;
    cout<<"3. Check for the leap Year"<<endl;
    cout<<"Enter choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    Date d1;
    d1.initDate();

    while((choice = menu())!=0){
        switch(choice){
            case 1:
                d1.printDateOnConsole();
                break;
            case 2:
                d1.acceptDateFromConsole();
                break;
            case 3:
                d1.isLeapYear();
                break;
            default:
                cout<<"Wrong choice!!! Please Enter the Correct Value!!!";
                break;
        }
    }
    return 0;
}
