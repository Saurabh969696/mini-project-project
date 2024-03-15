/*Problem statement: fare calculation for journey ticket booking for onw-way/two-way journey/s.
  Data  supplied by user: journey number,number of passengers,age of each passenger and choice of one-way or two-way
  ticket booking.
  journey No. and fares-1001:Solapur to Pune(fare-Rs 400)
                        1002:Pune to Solapur(fare-Rs 400)
                        1003:Solapur to Hyderabad(fare-Rs 600)
                        1004:Hyderabad to Solapur(fare-Rs 600)
                        1005:Solapur to Mumbai(fare-Rs 800)
                        1006:Mumbai to Solapur(fare-Rs 800)
                        1007:Solapur to Delhi(fare-Rs 1500)
                        1008:Delhi to Solapur(fare-Rs 1500)
                        */
//program in c to calculate fare as per journey selected by user
#include<stdio.h>
int calculate_fare();      //function prototype declaration for the fare calculus
int main()
{
    int choice;
    float one_way,final_pay;
    one_way=calculate_fare();    //function called,control shifts to calculate_fare block
    if(one_way>0)
    {
        printf("\n Whether you wish to book two way ticket?\n Enter 1 for yes and 0 for no:");
        //getting choice for onw_way or two_way ticket booking
        scanf("%d",&choice);
        if(choice==1)
        final_pay=2*one_way;     //if yes then multiply the one_way
        else
        final_pay=one_way;
        printf("\n Final payment to be done is %2f",final_pay);

    }
    else           //executed when calcuate_fare returns 0, i.e., invalid input
    printf("\n Transaction cancelled.Try once again.");
    return 0;      //end of main function

}
int calculate_fare()           //detailed block for function  calculate_fare
{
    int i,n,age,journey;
    float fare,total=0,passfare;
    printf("\n Enter journey number:");
    scanf("%d",&journey);           //scanning journey number
    switch (journey)               //switch as per journey number entered to assign fare value for processing
    {
    case 1001:
        fare=400;
        break;
    case 1002:
        fare=400;
        break;
    case 1003:
        fare=600;
        break;
    case 1004:
        fare=600;
        break;
    case 1005:
        fare=800;
        break;
    case 1006:
        fare=800;
        break;
    case 1007:
        fare=1500;
        break;
    case 1008:
        fare=1500;
        break;
    default:
        printf("\n Entered wrong journey code.");
        break;
    }
    printf("\n Enter number of passengers:");
    scanf("%d",&n);                           //getting number of passengers
    for(i=1;i<=n;i++)                //for loop to collect age and calculate applicable fare of each passenger
    {
        printf("Enter the age of passenger %d:",i);
        scanf("%d",&age);
        if(age<5)
        {
            passfare=0;
        }
        if((age>=5)&&(age<12))
        {
            passfare=fare/2;
        }
        if(age>59)
        {
            passfare=fare/2;
        }
        if((age>=12)&&(age<60))
        {
            passfare=fare;
        }
        total=total+passfare;               //summing up the fare applicable to all passengers one by one as per for loop
    }
    return total;

}