#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef char string[80];
class inventory

{
 private:
  string itemno, name ;
  int aqty, rol;
  static int tot;
  int lol;
  float cost, dp, tp, pp;


 public:
  inventory()
  {
  }
  void newentry()
  {
   cout<<"Enter the name of the product you wish to add to your inventory:";
   gets(name);
   cout<<"\nEnter the item number of the product:";
   gets(itemno);
   cout<<"\nEnter the cost of the product from factory:";
   cin>>cost;
   cout<<"\nEnter available quantity:";
   cin>>aqty;
   cout<<"\nEnter the discount percentage of the product:";
   cin>>dp;
   cout<<"\nEnter the tax percentage of the product:";
   cin>> tp;
   cout<<"\nEnter the profit percentage of the product:";
   cin>>pp;
   tot++;
   cout<<"Item Added!";
   getch();
  }
  void totinv()
  {cout<<endl;
   cout<<name<<"\t\t"<<itemno<<"\t\t"<<aqty<<"\t\t\t"<<rol;
  }
  void rolcalc()
  {
   if (aqty>50)
   rol=0;
   if (aqty>30&&aqty<=50)
   rol=1;
   if (aqty>15&&aqty<=30)
   rol=2;
   if (aqty<15)
   rol=3;
   }
  int checkno(string);
  int checkqty(int);
  float samtcalc();
  float profitcalc();
  int pcheckno(string);
} obj[10];

int inventory::tot=0;

int inventory::checkno(string a)
 {
 if (strcmp(a,itemno)==0)
 return 1;
 else
 return 0;
 }
int inventory::checkqty(int a)
{if (aqty<a)
return 0;
else
aqty=aqty-a;
return 1;
}
float inventory::samtcalc()
{
  return cost-cost*(dp/100)+cost*(tp/100)+cost*(pp/100);
}

float inventory::profitcalc()
{
return cost*(pp/100)-cost*(dp/100);
}

int inventory::pcheckno(string a)
{
int b;
b=strcmp(a,itemno);
if(b==0)
return 1;
else
return 0;
}
class sale: public inventory
{
 private:
 string billno;
 string sitemno;
 int sqt;
 float saleamt;
 static int totsale,profit;
 public:
 int makesale(int);
 void showtotalsale()
 {clrscr();
  cout<<"The total amount from sales is Rs. "<<totsale;
  cout<<"\nThe total profit from sales is Rs. "<<profit;
  getch();
 }
}s[10];

int sale::totsale=0;
int sale::profit=0;
int sale::makesale(int c)
{ int a,b=0;
  char ch;
  do
  {
  cout<<"\nHow many would you like to sell? ";
  cin>>sqt;
  b=0;
  if(obj[c].checkqty(sqt)==0)
  {cout<<"Sorry, you do not have enough stock!";
  do{
  cout<<"\nWould you like to:\n1. Sell Less\n2. Go Back to Main Menu";
   b=2;
   ch=getch();
   clrscr();
   switch(ch)
   {
   case '1':  break;
   case '2': return 0;

   default: cout<<"Please Enter a valid option!";
	    b=1;
   }
   }while (b==1);
   }
   }while (b==2);
saleamt=a*obj[c].samtcalc();
totsale=totsale+saleamt;
profit=profit+a*obj[c].profitcalc();
obj[c].rolcalc();
cout<<"Item Sold!";
getch();
return 1;
}


class purchase: public inventory
{



};


void main()
{
char ch,ch1;
int a=0,b=0,c,i;
string st;

do
{
clrscr();
cout<<"Hello! Welcome to your Inventory Software!\nPlease select an option:";
cout<<"\n1. Inventory";
cout<<"\n2. Sales";
cout<<"\n3. Purchases";
cout<<"\n4. Exit";
ch=getch();
clrscr();
switch(ch)
{
case '1':  cout<<"What would you like to do?\n1. Add an Item\n2. View Inventory";
	 ch=getch();
	 clrscr();
	 if(ch=='1')
	 {obj[a].newentry();
	 a++;

	 }
	 if(ch=='2')
	 {
	 cout<<"Item\t\tItem Number\t\tQuantity left\t\tReorder Level\n";
	 for (i=0; i<a; i++)
	  obj[i].totinv();
	  getch();
	 }
	 break;
case '2':cout<<"What would you like to do?\n1. Sell an Item\n2. View Sales Amount and Profit";
	 ch=getch();
	 if(ch=='1')
	{
	 do{
	 clrscr();
	 cout<<"Enter the item code of the item you wish to sell:";
	 gets(st);
	 for (i=0; i<a; i++)
	 {
	 if(obj[i].checkno(st)==1)
	 break;
	 }
	 if (a==i)
	 {cout<<"Please Enter a Valid Code!";
	 getch();
	 }
	 } while(a==i);
	 s[i].makesale(i);
	 }
	 if(ch=='2')
	 {s[0].showtotalsale();
	 }
	 break;
case '3':cout<<"What would you like to do?\n1. Purchase an item\n2. View Purchase Details";
	 ch=getch();
	 if (ch=='1')
	 {
	 do{
	 clrscr();
	 cout<<"Enter the item code of the item you wish to purchase:";
	 gets(st);
	 for (i=0; i<a; i++)
	 {
	 if(obj[i].pcheckno(st)==1)
	 break;
	 }
	 if (a==i)
	 {cout<<"Please Enter a Valid Code!";
	 getch(); }
	 }while(a==i);

	 }
	 break;


case '4': b=1;
	break;

}
}while(b==0);


}
