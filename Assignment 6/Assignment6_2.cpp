#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        double salary;
    
    public:
        Employee(){
            cout<<"Employee() Parameterless Constructor!!!"<<endl;
        }

        Employee(int id , double salary){
            this->id = id;
            this->salary = salary;
        }

        void setId(int id){
            this->id = id;
        }

        int getId(){
            return this->id;
        }

        void setSalary(double salary){
            this->salary = salary;
        }

        double getSalary(){
            return this->salary;
        }

        virtual void accept(){
            cout<<"Enter the id:- "<<endl;
            cin>>this->id;

            cout<<"Enter the salary:- "<<endl;
            cin>>this->salary;
        }

        virtual void display(){
            cout<<"The id is:- "<<this->id<<endl;

            cout<<"The salary is:- "<<this->salary<<endl;
        }
};

class Manager: virtual public Employee{
    private:
        double Bonus;

    protected:
        void acceptManager(){
            cout<<"Enter the bonus of the manager:- "<<endl;
            cin>>this->Bonus;
        }

        void displayManager(){
            cout<<"The Bonus is:- "<<this->Bonus<<endl;;
        }

    public:
        Manager(){
            cout<<"Manager() parameterless Constructor!!!"<<endl;
        }

        Manager(int id , double salary , double Bonus):Employee(id , salary){
            this->Bonus = Bonus;
        }

        void setBonus(double Bonus){
            this->Bonus = Bonus;
        }

        double getBonus(){
            return this->Bonus;
        }

        void accept(){
            Employee ::accept();
            acceptManager();
        }

        void display(){
            Employee :: display();
            displayManager();
        }
};

class Salesman : virtual public Employee{
    private:
        double commission;
    
    protected:
        void acceptSalesman(){
            cout<<"Enter the comission:- "<<endl;
            cin>>this->commission;
        }

        void displaySalesman(){
            cout<<"The comission is:- "<<this->commission<<endl;
        }


    public:
        Salesman(){
            cout<<"Salesman() parameterless Constructor!!!"<<endl;
        }

        Salesman(int id , double salary , double commission):Employee(id , salary){
            this->commission = commission;
        }

        void setCommission(double commission){
            this->commission = commission;
        }

        double getCommission(){
            return this->commission;
        }

        void accept(){
            Employee ::accept();
            acceptSalesman();
        }

        void display(){
            Employee :: display();
            displaySalesman();
        }
};

class SalesManager : public Manager , public Salesman{
    public:
        SalesManager(){
            cout<<"SalesManager() parameterless Constructor!!!"<<endl;
        }

        SalesManager(int id , double salary , double bonus , double commission) : Employee(id , salary){
            //
        }

        void accept(){
            Employee :: accept();
            Manager :: acceptManager();
            Salesman :: acceptSalesman();
        }

        void display(){
            Employee :: display();
            Manager :: displayManager();
            Salesman :: displaySalesman();
        }
};

int main(){
    // SalesManager obj;
    // obj.accept();
    // obj.display();

    // Manager m;
    // m.accept();
    // m.display();

    // Salesman s;
    // s.accept();
    // s.display();

    Employee *ptr = new SalesManager();
    ptr->accept();
    ptr->display();

}
