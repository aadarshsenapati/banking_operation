//Banking operation

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class Bank{
    
    public:
    int x,y,valid=0;
    char pass[20];
    Bank(){
        do{
        cout<<"Enter the initial amount: ";
        cin>>x;
        if(x<1000)
            cout<<"\nThe mimimum balance should be 1000\n";
        }while(x<=1000);
        cout<<"Enter the password: ";
        int i;
        for(i=0;i!=20;i++){
            pass[i]=getch();
            if(pass[i]==13)
                break;
            cout<<"*";
        }
        pass[i]='\0';
    }
    void deposite(){
        check_password();
        if(valid==1){
        cout<<"\nEnter the amount you want to deposite: \n";
        cin>>y;
        x=x+y;
        }
    }
    void withdraw(){
        check_password();
        if(valid==1){
        cout<<"\nEnter the amount you want to withdraw: \n";
        cin>>y;
        if(x-y<0){
            cout<<"\nInsufficient balance\n";
        }else{
            x=x-y;
        }
        }
    }
    void check_bal(){
        check_password();
        if(valid==1){
        cout<<"\nYour balance is: \n"<<x;
        }
    }
    void check_password(){
        char check[20];
        cout<<"Enter the password: ";
        int i;
        for(i=0;i!=20;i++){
            check[i]=getch();
            if(check[i]==13)
                break;
            cout<<"*";
        }
        check[i]='\0';
        if(strcmp(pass,check)==0){
            valid=1;
        }else{
            cout<<"\nInvalid\n";
        }
    }
    void change_pass(){
        check_password();
        if(valid==1){
        cout<<"Enter the new password: ";
        int i;
        for(i=0;i!=20;i++){
            pass[i]=getch();
            if(pass[i]==13)
                break;
            cout<<"*";
        }
        pass[i]='\0';
        }
    }
};

main(){
    Bank obj;
    int temp,cont=1;
    do
    {
    cout<<"\n***********MENU************\n1.Check balance\n2.Deposite\n3.Withdraw\n4.Change password\n5.exit\nWhat do you want to do: ";
    cin>>temp;
    
    switch(temp){
        case 1:
            obj.check_bal();
            break;
        case 2:
            obj.deposite();
            break;
        case 3:
            obj.withdraw();
            break;
        case 4:
            obj.change_pass();
            break;
        case 5:
            cont=0;
            break;
    }
    }while(cont==1);
}