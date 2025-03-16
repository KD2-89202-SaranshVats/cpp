#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;

    public:
        Date(){
            cout<<"Inside Date() Parameterless Customers:- "<<endl;
        }

        Date(int day , int month , int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }

        void acceptDate(){
            cout<<"Enter the day:- "<<endl;
            cin>>this->day;

            cout<<"Enter the month:- "<<endl;
            cin>>this->month;

            cout<<"Enter the year:- "<<endl;
            cin>>this->year;
        }

        void displayDate(){
            cout<<"The date is:- "<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
        }
};

class Person{
    private:
        string name;
        string address;
        Date dob;

    public:
        Person(){
            cout<<"Inside Person() Parameterless Constructor:- "<<endl;
        }

        Person(string name , string address , int day , int month , int year) : dob (day , month , year){
            this->name = name;
            this->address = address;
        }

        void acceptPerson(){
            cout<<"Enter the name of the person:- "<<endl;
            cin>>this->name;

            cout<<"Enter the address of the Person:- "<<endl;
            cin>>this->address;

            dob.acceptDate();
        }

        void displayPerson(){
            cout<<"The name is:- "<<this->name<<endl;
            cout<<"The address is:- "<<this->address<<endl;
            dob.displayDate();
        }
};

class Student{
    private:
        int id;
        int marks;
        string course;
        Date *doj;
        Date *ed;

    public:
        Student(){
            cout<<"Inside Student() parameterless Constructor:- "<<endl;
            doj = NULL;
            ed = NULL;
        }

        Student(int id , int marks , string course){
            this->id = id;
            this->marks = marks;
            this->course = course;
        }

        void acceptStudent(){
            cout<<"Enter the id of the student:- "<<endl;
            cin>>this->id;

            cout<<"Enter the marks of the student:- "<<endl;
            cin>>this->marks;

            cout<<"Enter the course of the student:- "<<endl;
            cin>>this->course;

            doj = new Date();
            cout<<"Enter the joining date of the student:- "<<endl;
            doj->acceptDate();

            ed = new Date();
            cout<<"Enter the ending date of the student:- "<<endl;
            ed->acceptDate();
        }

        void displayStudent(){
            cout<<"The id of the student is:- "<<this->id<<endl;
            cout<<"The marks of the student is:- "<<this->marks<<endl;
            cout<<"The course of the student is:- "<<this->course<<endl;

            if(doj!=NULL){
                cout<<"The joining date of the Student is:- "<<endl;
                doj->displayDate();
            }

            if(ed!=NULL){
                cout<<"The ending date of the Student is:- "<<endl;
                ed->displayDate();
            }
        }
};

int menu(){
    int choice;
    cout<<"0. EXIT FROM THE SYSTEM!!!"<<endl;
    cout<<"1. Add Person details to the system!!!"<<endl;
    cout<<"2. Display Person details from the system!!!"<<endl;
    cout<<"3. Add Student details to the system!!!"<<endl;
    cout<<"4. Display student from the system!!!"<<endl;
    cout<<"Enter choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
//     Person p;
//     p.acceptPerson();
//     p.displayPerson();
// }

// Student s;
// s.acceptStudent();
// s.displayStudent();

Person p;
Student s;
int choice;

while((choice = menu())!=0){
    switch(choice){
        case 1:
            p.acceptPerson();
            break;
        case 2:
            p.displayPerson();
            break;
        case 3:
            s.acceptStudent();
            break;
        case 4:
            s.displayStudent();
            break;
        default:
            cout<<"Wrong choice!!! Please eneter the correct choice!!!"<<endl;
            break;
    }
}
return 0;
}