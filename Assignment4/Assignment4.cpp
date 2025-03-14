#include<iostream>
using namespace std;

class Time{
    private:
        int h;
        int m;
        int s;

    public:
        Time(){}
        Time(int h , int m , int s){
            this->h = h;
            this->m = m;
            this->s = s;
        }

        void printTime(){
            cout<<"Time is:- "<<this->h<<":"<<this->m<<":"<<this->s<<endl;
        }

        void setHour(){
            cout<<"Enter the hour that you want:- "<<endl;
            cin>>this->h;
        }

        void setMinute(){
            cout<<"Enter the min that you want:- "<<endl;
            cin>>this->m;
        }

        void setSeconds(){
            cout<<"Enter the seconds that you want:- "<<endl;
            cin>>this->s;
        }

        int getHour(){
            return this->h;
        }

        int getMinute(){
            return this->m;
        }

        int getSeconds(){
            return this->s;
        }
};

int main(){
    Time **ptr = new Time *[5];
    ptr[0] = new Time(10,12,15);
    ptr[1] = new Time(12,2,4);
    ptr[2] = new Time(1,2,3);
    ptr[3] = new Time(4,5,6);
    ptr[4] = new Time(20,18,20);

    for(int i =0 ; i < 5 ; i++){
        ptr[i]->printTime();
    }

    for(int i = 0 ; i<5 ; i++){
        delete ptr[i];
        ptr[i] = NULL;
    }

    delete [] ptr;
    ptr = NULL;

}