#include<iostream>
using namespace std;

class Product{
    private:
        int id;
        string title;
        double price;

    public:
        Product(){
            cout<<"Product() Parameterless Constructor!!!"<<endl;
        }
        Product(int id , string title , double price){
            this->id = id;
            this->title = title;
            this->price = price;
        }

        virtual void accept(){
            cout<<"Enter the id:- "<<endl;
            cin>>this->id;

            cout<<"Enter the title:- "<<endl;
            cin>>this->title;

            cout<<"Enter the price:- "<<endl;
            cin>>this->price;
        }
        virtual void display(){
            cout<<"The id is:- "<<this->id<<endl;
            cout<<"The title is:- "<<this->title<<endl;
            // cout<<"The Price is:- "<<this->price<<endl;
        }

        void setPrice(double price){
            this->price = price;
        }

        int getPrice(){
            return this->price;
        }
};

class Book: virtual public Product{
    private:
        string author;
    public:
        Book(){
            cout<<"Book() Parameterless Constructor!!!"<<endl;
        }

        Book(int id , string title , string author , double price) : Product(id , title , price){
            this->author = author;
        }

        void accept(){
            Product :: accept();
            cout<<"Enter the author of the book:- "<<endl;
            cin>>this->author;
            double new_price = getPrice() - (getPrice() * 0.1);
            setPrice(new_price);
        }
        
        void display(){
            Product :: display();
            cout<<"The author of the boook is:- "<<this->author<<endl;
            cout<<"The priceof the book after discount is:- "<<this->getPrice()<<endl;
        }
};

class Tape : virtual public Product{
    private:
        string artist;
    
    public:
        Tape(){
            cout<<"Tape():Parameterless Constructor:!!!"<<endl;
        }

        Tape(int id , string title , string artist , double price) : Product(id , title , price){
            this->artist = artist;
        }

        void accept(){
            Product :: accept();
            cout<<"Enter the artist of Tape:- "<<endl;
            cin>>this->artist;
            double new_price = getPrice() - (getPrice() * 0.05);
            setPrice(new_price);
        }

        void display(){
            Product :: display();
            cout<<"The artist of the tape is:- "<<this->artist<<endl;
            cout<<"The Price of the Tape after discount is:- "<<this->getPrice()<<endl;
        }

};

int menu(){
    int choice;
    cout<<"0. EXIT FROM THE SYSTEM!!!"<<endl;
    cout<<"1. ADD BOOK TO THE SYSTEM!!!"<<endl;
    cout<<"2. ADD TAPE TO THE SYSTEM!!!"<<endl;
    cout<<"3. DISPLAY ALL ITEMS!!!"<<endl;
    cout<<"4. DIPSLAY ALL BOOKS"<<endl;
    cout<<"5. DISPLAY ALL TAPES"<<endl;
    cout<<"6. DISPLAY THE BILL FOR ALL BOOKS"<<endl;
    cout<<"7. DISPLAY THE BILL FOR ALL TAPES"<<endl;
    cout<<"Enter choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    Product *arr[3];
    int new_bill = 0;
    int tape_bill = 0;
    int index = 0;
    int choice;
    while((choice = menu())!=0){
        switch(choice){
            case 1:
                if(index<3){
                    arr[index] = new Book();
                    arr[index]->accept();
                    index++;
                }
                else{
                    cout<<"Sorry!!!There is no space left"<<endl;
                }
                break;
            
            case 2:
                if(index<3){
                    arr[index] = new Tape();
                    arr[index]->accept();
                    index++;
                }
                break;

            case 3:
                for(int i = 0 ; i<index ; i++){
                    arr[i]->display();
                }
                break;

            case 4:
                for(int i = 0; i < index ;  i++){
                    if(typeid(*arr[i]) == typeid(Book)){
                        arr[i]->display();
                    }
                }
                break;

            case 5:
                for(int i = 0 ; i < index ; i++){
                    if(typeid(*arr[i])==typeid(Tape)){
                        arr[i]->display();
                    }
                }
                break;

            case 6:
                for(int i = 0 ; i < index ; i++){
                    if(typeid(*arr[i])==typeid(Book)){
                        new_bill = new_bill + arr[i]->getPrice() ;
                        // arr[i]->setPrice(new_bill);
                    }
                }
                cout<<"The Total Bill for books:- "<<new_bill<<endl;
                new_bill = 0;
                break;
            
            case 7:
                for(int i = 0 ; i < index ; i++){
                    if(typeid(*arr[i])==typeid(Tape)){
                        tape_bill = arr[i]->getPrice() + tape_bill;
                    }
                    // arr[i]->setPrice(tape_bill);
                }
                cout<<"The Total Bill Generated fro Tapes is:- "<<tape_bill<<endl;
                tape_bill = 0;
                break;
                
            
            default:
                cout<<"Wrong Choice!!!Please Enter the correct choice!!!"<<endl;
                break;

        }
    }
    return 0;
}