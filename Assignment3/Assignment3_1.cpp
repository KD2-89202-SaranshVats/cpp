#include<iostream>
using namespace std;

class Volume{
    private:
        float length;
        float width;
        float height;
    
    public:
        Volume(){
            this->length = 10;
            this->width = 20;
            this->height = 30;
        }

        Volume(float length , float width , float height){
            this->length = length;
            this->width = width;
            this->height = height;
        }

        Volume(float value){
            this->length = value;
            this->width = value;
            this->height = value;
        }

        void display(){
            cout<<"Volume of Box is:- "<<(this->length) * (this->width) * (this->height)<<endl;
        }
};

int menu(){
    int choice;
    cout<<"0. EXIT FROM THE SYSTEM!!!"<<endl;
    cout<<"1. Calculate Volume with default values:- "<<endl;
    cout<<"2. Calculate Volume with length , breadth and height with the same value:- "<<endl;
    cout<<"3. Calculate Volume with different length , breadth and height values:- "<<endl;
    cout<<"Enter Choice:- "<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    Volume o;
    Volume obj(10);
    Volume obj2(50,50,50);

    while((choice = menu())!=0){
        switch (choice){
            case 1:
                o.display();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj2.display();
                break;
            default:
                cout<<"Wrong Choice!!!! Please enter the correct choice!!!"<<endl;
                break;
        }
    }
    return 0;
}