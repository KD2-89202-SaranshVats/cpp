#include<iostream>

struct Date{
    int day;
    int month;
    int year;
};

void acceptDateFromConsole(struct Date *ptrDate){
    printf("Enter the day:- \n");
    scanf("%d",&ptrDate->day);

    printf("Enter the month:- \n");
    scanf("%d",&ptrDate->month);

    printf("Enter the year:- \n");
    scanf("%d",&ptrDate->year);
}

void printDateOnConsole(struct Date *ptrDate){
    printf("Date = %d / %d / %d",ptrDate->day,ptrDate->month,ptrDate->year);
}

int main(){
    struct Date d;
    acceptDateFromConsole(&d);
    printDateOnConsole(&d);
    return 0;
}