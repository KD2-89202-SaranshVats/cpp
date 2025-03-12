#include<iostream>
using namespace std;

class TollBooth{
    private:
        unsigned int paying_cars;
        unsigned int non_paying_cars;
        double total_money;
    
    public:
        TollBooth(){
            this->paying_cars = 0;
            this->non_paying_cars = 0;
            this->total_money = 0;
        }

        void payingCar(){
            this->paying_cars = paying_cars + 1;
            this-> total_money = total_money + 0.50;
        }

        void noPayCar(){
            this->non_paying_cars = non_paying_cars + 1;
            // this->total_money = total_money + 0;
        }

        void printOnConsole(){
            cout<<"The total Number of Paying Cars:- "<<this->paying_cars<<endl;
            cout<<"The total amount of paying cars:- "<<this->total_money<<endl;
            cout<<"The total Number of Non-paying cars:- "<<this->non_paying_cars<<endl;
        }
};

int menu(){
    int choice;
    cout<<"0. EXIT FROM THE SYSTEM!!!"<<endl;
    cout<<"1. Pay the toll charge:- "<<endl;
    cout<<"2. Donot pay the toll charge:- "<<endl;
    cout<<"3. To show the Day Collection "<<endl;
    cout<<"Enter Choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    TollBooth c;

    while((choice = menu())!=0){
        switch (choice){
            case 1:
                c.payingCar();
                break;
            case 2:
                c.noPayCar();
                break;
            case 3:
                c.printOnConsole();
                break;
            default :
                cout<<"Wrong choice!!! Plesae enter the correct value!!!"<<endl;
                break;
        }
    }
    return 0;
}