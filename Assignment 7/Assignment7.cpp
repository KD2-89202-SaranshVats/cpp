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

int menu(){
    int choice;
    cout<<"0.EXIT FROM THE SYSTEM!!!"<<endl;
    cout<<"1. Add MANAGER   "<<endl;
    cout<<"2. Add SALESMAN  "<<endl;
    cout<<"3. ADD SALESMANAGER"<<endl;
    cout<<"4. DISPLAY ALL MANAGERS"<<endl;
    cout<<"5. DISPLAY ALL SALESMANA"<<endl;
    cout<<"6. DISPLAY ALL SALESMANAGERS"<<endl;
    cout<<"7. DISPLAY THE COUNT OF ALL MANAGERS"<<endl;
    cout<<"8. DISPLAY THE COUNT OF ALL SALESMAN"<<endl;
    cout<<"9. DISPLAY THE COUNT OF ALL SALESMANAGER"<<endl;
    cout<<"Enter choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int count_managers = 0;
    int count_salesman = 0;
    int count_salesmanager = 0;
    int choice;
    int index=0;
    Employee *ptr[10];
    while((choice = menu())!=0){
        switch(choice){
            case 1:
                if(index<10){
                    ptr[index]=new Manager();
                    ptr[index]->accept();
                    index++;
                }
                else{
                    cout<<"There is no empty vacancy!!!"<<endl;
                }
                break;

            case 2:
                if(index<10){
                    ptr[index] = new Salesman();
                    ptr[index]->accept();
                    index++;
                }
                else{
                    cout<<"There is no empty vacancy!!!"<<endl;
                }
                break;

            case 3:
                if(index<10){
                    ptr[index] = new SalesManager();
                    ptr[index]->accept();
                    index++;
                }
                else{
                    cout<<"There is no empty vacancy!!!"<<endl;
                }
                break;

            case 4:
                for(int i = 0 ; i<index ; i++){
                    if(typeid(*ptr[i])==typeid(Manager)){
                        ptr[i]->display();
                    }
                }
                break;

            case 5:
                for(int i = 0; i < index ; i++){
                    if(typeid(*ptr[i])==typeid(Salesman)){
                        ptr[i]->display();
                    }
                }
                break;
            
            case 6:
                for(int i = 0 ; i < index ; i++){
                    if(typeid(*ptr[i])==typeid(SalesManager)){
                        ptr[i]->display();
                    } 
                }
                break;
            
            case 7:
                for(int i = 0; i < index ; i++){
                    if(typeid(*ptr[i])==typeid(Manager)){
                        count_managers = count_managers + 1;
                    }
                }
                cout<<"The number of Managers are:- "<<count_managers<<endl;
                count_managers = 0;
                break;

            case 8:
                for(int i = 0 ; i < index ; i++){
                    if(typeid(*ptr[i])==typeid(Salesman)){
                        count_salesman = count_salesman + 1;
                    }
                }
                cout<<"The number of Salesman are:- "<<count_salesman<<endl;
                count_salesman=0;
                break;

            case 9:
                for(int i = 0 ; i < index ; i++){
                    if(typeid(*ptr[i])==typeid(SalesManager)){
                        count_salesmanager = count_salesmanager + 1;
                    }
                }
                cout<<"The number of SalesManager are:- "<<count_salesmanager<<endl;
                count_salesmanager = 0;
                break;    

            default:
                cout<<"Wrong choice!!! Please Enter the Correct Choice!!!"<<endl;
                break;
        }
    }
    return 0;
}
