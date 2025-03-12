#include<iostream>
using namespace std;

namespace NStudent{
    class Student{
        private:
            int rollno;
            string name;
            int marks;
        
        public:
            Student(){
                this->rollno = 0;
                this->name = "Koi Nhi";
                this->marks = 0;
            }
            
            void acceptStudentFromConsole(){
                cout<<"Enter the roll no:- "<<endl;
                cin>>this->rollno;

                cout<<"Enter the name:- "<<endl;
                cin>>this->name;

                cout<<"Enter the marks:- "<<endl;
                cin>>this->marks;
            }

            void printStudentFromConsole(){
                cout<<"The roll no is:- "<<this->rollno<<endl;
                cout<<"The name is:- "<<this->name<<endl;
                cout<<"The marks is:- "<<this->marks<<endl;
            }
    };
}

int menu(){
    int choice;
    cout<<"0. EXIT FROM THE SYSTEM!!!"<<endl;
    cout<<"1. Accept Student From Console"<<endl;
    cout<<"2. Print Student on console"<<endl;
    cout<<"Enter the choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    NStudent :: Student s;

    while((choice = menu())!=0){
        switch (choice){
            case 1:
                s.acceptStudentFromConsole();
                break;
            case 2:
                s.printStudentFromConsole();
                break;
            default :
                cout<<"Wrong choice!!! Please Enter the Correct Choice!!!"<<endl;
                break;
        }
    }
    return 0;
}