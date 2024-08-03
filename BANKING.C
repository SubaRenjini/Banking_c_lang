#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
char phone[50];
char ac[50];
char password[50];
float balance;
};

int main()
{
struct user usr,usr1;
FILE *fp;
char filename[50],phone[50],pword[50];
int opt,choice;
char cont = 'y';
float amount;
printf("\nWhat do you want to do?");
printf("\n\n1. Register an account");
printf("\n2.Login to an account");

printf("\n\nYour choice:\t");
scanf("%d",&opt);

if(opt == 1){
system("cls");
printf("Enter your account no:");
scanf("%s",usr.ac);
printf("\nEnter your phone no:");
scanf("%s",usr.phone);
printf("\nEnter your new password:");
scanf("%s",usr.password);
usr.balance=0;
strcpy(filename,usr.phone);
fp = fopen(strcat(filename,".dat"),"w");
fwrite(&usr,sizeof(struct user),1,fp);
if(fwrite != 0){
printf("\n\nAccount successfully registered");
}
else{
printf("\n\nSomething went wrong please try again");
}
fclose(fp);
}

if(opt == 2){
system("cls");
printf("\nPhone number:");
scanf("%s",phone);
printf("Password:");
scanf("%s",pword);
strcpy(filename,phone);
fp=fopen(strcat(filename,".dat"),"r");
if(fp == NULL)
{
printf("\nAccount number not registered");
}
else
{
fread(&usr,sizeof(struct user),1,fp);
fclose(fp);
if(!strcmp(pword,usr.password))
{
while(cont == 'y')
{
system("cls");
printf("\nPress 1 for balance inquiry");
printf("\nPress 2 for depositing cash");
printf("\nPress 3 for cash withdrawl");
printf("\nPress 4 for online transfer");
printf("\nPress 5 for password change");
printf("\n\nYour choice:\t");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("\nYour current balance is Rs.%.2f",usr.balance);
break;
case 2:
printf("\nEnter the amount:");
scanf("%f",&amount);
usr.balance += amount;
fp = fopen(filename,"w");
fwrite(&usr,sizeof(struct user),1,fp);
if(fwrite != NULL) printf("\nSuccessfully deposited");
fclose(fp);
break;
case 3:
printf("\nEnter the amount:");
scanf("%f",&amount);
usr.balance -= amount;
fp = fopen(filename,"w");
fwrite(&usr,sizeof(struct user),1,fp);
if(fwrite != NULL) printf("\nYou have withdraw Rs.%2f",amount);
fclose(fp);
break;
case 4:
printf("\nPlease enter the phone number to transfer the balance:");
scanf("%s",phone);
printf("\nPlease enter the amount to transfer:");
scanf("%f",&amount);
if(amount > usr.balance) printf("\nInsufficient balance");
else
{
strcpy(filename,phone);
fp = fopen(strcat(filename,".dat"),"r");
fread(&usr1,sizeof(struct user),1,fp);
fclose(fp);
fp= fopen(filename,"w");
usr1.balance += amount;
fwrite(&usr1,sizeof(struct user),1,fp);
fclose(fp);
if(fwrite != NULL)
{
printf("\nYouhave successfully transfered Rs.%.2f to %s",amount,phone);
strcpy(filename,usr.phone);
fp = fopen(strcat(filename,".dat"),"w");
usr.balance -= amount;
fwrite(&usr,sizeof(struct user),1,fp);
fclose(fp);
}
}
break;
case 5:
printf("\nPlease enter your new password:");
scanf("%s",pword);
fp = fopen(filename,"w");
strcpy(usr.password,pword);
fwrite(&usr,sizeof(struct user),1,fp);
if(fwrite != NULL)
printf("\nPassword successfully changed");
break;
default:
printf("\nInvalid option");
}

printf("\nDo you want to continue the transaction [y/n]");
scanf("%s",&cont);
}
}
else
{
printf("\nInvalid password");
}
}
}
return 0;
}
