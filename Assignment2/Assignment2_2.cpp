#include<iostream>
using namespace std;

class Student{
    private:
        int rollno;
        string name;
        double marks;
    
    public:
        void initStudent(){
            rollno = 99;
            name = "Rakul";
            marks = 90.25;
        }

        void acceptStudentFromConsole(){
            cout<<"Enter the rollno:- "<<endl;
            cin>>rollno;

            cout<<"Enter the name:- "<<endl;
            cin>>name;

            cout<<"Enter the marks:- "<<endl;
            cin>>marks;
        }

        void printStudentOnConsole(){
            cout<<"The rollno is:- "<<rollno<<endl;
            cout<<"The name is:- "<<name<<endl;
            cout<<"The marks is:- "<<marks<<endl;
        }
};

int menu(){
    int choice;
    cout<<"0. Exit from the System!!!"<<endl;
    cout<<"1. Accept from the Student:- "<<endl;
    cout<<"2. Display from the student:- "<<endl;
    cout<<"Enter choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    Student s;
    s.initStudent();

    while((choice = menu())!=0){
        switch(choice){
            case 1:
                s.acceptStudentFromConsole();
                break;
            case 2:
                s.printStudentOnConsole();
                break;
            default:
                cout<<"Wrong choice!!!!Please Enter the correct value!!!"<<endl;
                break;
        }
    }
    return 0;
}