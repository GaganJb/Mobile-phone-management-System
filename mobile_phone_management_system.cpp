#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void password();
void loading();
void menu();
//*************************************************************************
//
//                          PRODUCT DETAILS
//
//*************************************************************************
class mobile
{
 char coname[20];
 char model[20];
 float  price;
 public:
  char *getmodel()
  {
   return model;
  }
 void in()
 {

  textbackground(GREEN);
  textcolor(BLACK);
  clrscr();
  gotoxy(10,5);
  cout<<"Enter the company name ";
  gotoxy(40,5);
  gets(coname);
  gotoxy(10,7);
  cout<<"Enter the model name";
  gotoxy(40,7);
  gets(model);
  gotoxy(10,9);
  cout<<"Enter the price";
  gotoxy(40,9);
  cin>>price;
 }
 void out()
 {
  textbackground(GREEN);
  textcolor(BLACK);
  clrscr();
  gotoxy(10,5);
  cout<<"The name of the phone is: ";
  gotoxy(36,5);
  cout<<coname<<" "<<model<<endl;
  gotoxy(10,7);
  cout<<"The price is : ";
  gotoxy(36,7);
  cout<<price;
 }
}o;
//*******************FUNCTION TO CREATE FILE FOR PHONE INFO******************
void create()
{
fstream f;
f.open("mobile.dat",ios::out|ios::app);
o.in();
f.write((char*)&o,sizeof(o));
f.close();
}
//*******************FUNCTION TO DISPLAY FILE CONTENTS ****************
void display()
{

 fstream f;
 f.open("mobile.dat",ios::in);
 f.read((char*)&o,sizeof(o));
 while(!f.eof())
 {
  o.out();
  getch();
  f.read((char*)&o,sizeof(o));
 }
f.close();
}
//****************FUNCTION TO SEARCH MOBILE PHONE BY MODEL NAME********
 void search()
 {
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  char n[20];
  fstream f;
  f.open("mobile.dat",ios::in);
  gotoxy(10,5);
  cout<<"Enter the model name to be searched ";
  gotoxy(48,5);
  gets(n);
  int flag=0;
  f.read((char*)&o,sizeof(o));
  while(!f.eof())
  {
   if(strcmpi(o.getmodel(),n)==0)
   {
    o.out();
    flag=1;
   }
    f.read((char*)&o,sizeof(o));
  }
  if(flag==0)
  {
    gotoxy(23,24);
    cout<<"Product not found!!!"<<endl;
  }
 f.close();
}
//*********************FUNCTION TO MODIFY MOBILE STOCK***************
 void modify()
 {

  textcolor(BLACK);
  textbackground(GREEN);
  clrscr();
  char n[20];
  fstream f, f1;
  f.open("mobile.dat",ios::in);
  f1.open("temp.dat",ios::out);
  gotoxy(10,5);
  cout<<"Enter the model name to be searched ";
  gotoxy(48,5);
  gets(n);
  int flag=0;
  f.read((char*)&o,sizeof(o));
  while(!f.eof())
  {
   if(strcmpi(o.getmodel(),n)==0)
   {
    o.in();
    f1.write((char*)&o,sizeof(o));
    flag=1;
   }
   else
    f1.write((char*)&o, sizeof(o));
    f.read((char*)&o,sizeof(o));
  }
  f.close();
  f1.close();
  f.open("mobile.dat",ios::out);
  f1.open("temp.dat",ios::in);
  f1.read((char*)&o,sizeof(o));
  while(!f1.eof())
  {
    f.write((char*)&o,sizeof(o));
    f1.read((char*)&o,sizeof(o));
   }
   f1.close();
   f.close();
  if(flag==0)
  {
    gotoxy(15,20);
    cout<<"Record not found"<<endl;
  }

}
// *****************FUNCTION TO DELETE MOBILE STOCK*************
 void del()
 {
  clrscr();
  textcolor(BLACK);
  textbackground(GREEN);
  char n[20];
  fstream f, f1;
  f.open("mobile.dat",ios::in);
  f1.open("temp.dat",ios::out);
  gotoxy(10,5);
  cout<<"Enter the model name to be searched ";
  gotoxy(48,5);
  gets(n);
  int flag=0;
  f.read((char*)&o,sizeof(o));
  while(!f.eof())
  {
   if(strcmpi(o.getmodel(),n)==0)
   {
      flag=1;
   }
   else
     f1.write((char*)&o,sizeof(o));
     f.read((char*)&o,sizeof(o));
  }
  f.close();
  f1.close();
  f.open("mobile.dat",ios::out);
  f1.open("temp.dat",ios::in);
  f1.read((char*)&o,sizeof(o));
  while(!f1.eof())
  {
    f.write((char*)&o,sizeof(o));
    f1.read((char*)&o,sizeof(o));
   }
   f1.close();
   f.close();
  if(flag==0)
  {
    gotoxy(23,24);
    cout<<"Record deleted"<<endl;
  }

}
void modsubmenu()
{
 textcolor(BLACK);
 textbackground(GREEN);
 clrscr();
 int x=0;
 gotoxy(10,5);
 cout<<" 1. Edit Product Info ";
 gotoxy(10,7);
 cout<<" 2. Delete Product Record ";
 gotoxy(10,10);
 cout<<" Enter your choice :";
 gotoxy(30,10);
 cin>>x;
 switch(x)
 {
  case 1:modify();
	 break;
  case 2:del();
	 break;
 }
}


//********************************************************************
//
//                        CUSTOMER INFORMATION
//
//********************************************************************
class customer
{
 char cusname[20];
 char cusadd[70];
 char phone[12];
 char phoncom[20];
 char phonemod[15];
 double phonprice;
 public:
  void cusin()
  {

   textcolor(BLACK);
   textbackground(GREEN);
   clrscr();

    gotoxy(10,5);
   cout<<"Enter the name of the customer";
   gotoxy(42,5);
   gets(cusname);
   gotoxy(10,7);
   cout<<"Enter the address ";
   gotoxy(40,7);
   gets(cusadd);
   gotoxy(10,9);
   cout<<"Enter the phone number ";
   gotoxy(42,9);
   cin>>phone;
   gotoxy(10,11);
   cout<<"Enter the brand name of the phone you want to buy :";
   gotoxy(62,11);
   gets(phoncom);
   gotoxy(10,13);
   cout<<"Enter the model name of the phone you want to buy :";
   gotoxy(62,13);
   gets(phonemod);
   gotoxy(10,15);
   cout<<"Enter the price of the phone :";
   gotoxy(42,15);
   cin>>phonprice;
 }
void cusout()
{

 textcolor(BLACK);
 textbackground(GREEN);
 clrscr();
 gotoxy(10,15);
 cout<<"The name of the customer is : ";
 gotoxy(55,15);
 cout<<cusname<<endl;
 gotoxy(10,16);
 cout<<"The address of the cudtomer is :";
 gotoxy(55,16);
 cout<<cusadd<<endl;
 gotoxy(10,17);
 cout<<"The phone number of the customer is :";
 gotoxy(55,17);
 cout<<phone<<endl;
 gotoxy(10,18);
 cout<<"The brand name of the phone you want to buy is :";
 gotoxy(55,18);
 cout<<phoncom<<endl;
 gotoxy(10,19);
 cout<<"The model name of the phone is :";
 gotoxy(55,19);
 cout<<phonemod<<endl;
 gotoxy(10,20);
 cout<<"The price of the phone is :";
 gotoxy(55,20);
 cout<<phonprice<<endl;

}
}c;
//************************CREATING FILE FOR CUSTOMER INFO****************
void custcreate()
{
 fstream f;
 f.open("cus.dat",ios::out);
 c.cusin();
 f.write((char*)&c,sizeof(c));

 f.close();
}
//**********************DISPLAYING CUSTOMER FILE CONTENTS****************
void custdisplay()
{
fstream f;
f.open("cus.dat",ios::in);
f.read((char*)&c,sizeof(c));

while(!f.eof())
{
 c.cusout();
 getch();
 f.read((char*)&c,sizeof(c));
}
f.close();
}

//************************************************************************
//
//                         PROGRAM CUSTOMISATION
//
//************************************************************************



void Front()
{
 textbackground(GREEN);
 textcolor(BLACK);
 clrscr();
  gotoxy(12,5);

 cout<<"-------- WELCOME TO THE DIGITAL MOBILE STORE-------  ";
 gotoxy(15,15);
 cout<<" PRESS ANY KEY TO CONTINUE : ";
 getch();
  loading();
}

void loading()
{
 textcolor(BLACK);
 textbackground(GREEN);
 clrscr();
 int i;
  gotoxy(15,12);

   gotoxy(33,5);
   cout<<"LOADING";
   gotoxy(23,6);
   for(int x=0;x<27;x++)
   {
      delay(300);
      cout<<"|";
  }



  clrscr();
 }

void password()
{

     textcolor(BLACK);
     textbackground(GREEN);
     clrscr();
     char a,b,c;

     clrscr();
     gotoxy(20,15);
     cout<<"ENTER THE PASSWORD : ";
     gotoxy(43,15);
     a=getch();
     cout<<"*";
     gotoxy(45,15);
     b=getch();
     cout<<"*";
     gotoxy(47,15);
     c=getch();
     cout<<"*";
     delay(800);

     if(a=='C' && b=='+' && c=='+')
     {
      gotoxy(55,50);
       cout<<" ACCESS GRANTED! ENJOY THE PROJECT! ";
       delay(1200);
       Front();
     }
      else
      {
	    clrscr();
	    cout<<"ACCESS DENIED! TRY AGAIN!( ONLY ONE TRY AVAILABLE)  ";
	    gotoxy(20,15);
	    cout<<"ENTER THE PASSWORD : ";
	    gotoxy(43,15);
	    a=getch();
	    cout<<"*";
	    gotoxy(45,15);
	    b=getch();
	    cout<<"*";
	    gotoxy(47,15);
	    c=getch();
	    cout<<"*";
	    delay(800);
	    if(a=='C' && b=='+' && c=='+')
	     {
	      delay(1200);
	      Front();
	     }
	    else
	     {
	      int i=3;
	      gotoxy(1,19);
	      cout<<"PASSWORD INCORRECT! TERMINATING PROGRAM In: ";
		   while(i>=0)
		     {
		       gotoxy(46,19);
		       delay(1500);
		       cout<<i;
		       i--;
		     }

	      exit(0);
	     }
      }



}

//********************************MAIN MENU*******************************
void menu()
{
 clrscr();
 int ch;
 char chr;
 password();
 do
 {

 textbackground(GREEN);
 textcolor(BLACK);
 clrscr();
 gotoxy(20,5);
 cout<<"***************** MENU **********************"<<endl;
 gotoxy(27,7);
 cout<<" 1. Add Mobile Stock"<<endl;
 gotoxy(27,9);
 cout<<" 2. Display Mobile Stock"<<endl;
 gotoxy(27,11);
 cout<<" 3. Search(by model name)"<<endl;
 gotoxy(27,13);
 cout<<" 4. Start shopping"<<endl;
 gotoxy(27,15);
 cout<<" 5. Modify Product Records"<<endl;
 gotoxy(27,17);
 cout<<" 6. Exit the store. ";
 gotoxy(27,19);
 cout<<" Enter your choice";
 gotoxy(48,19);
 cin>>ch;
  switch(ch)
  {
   case 1: create();
	   break;
   case 2: display();
	   break;
   case 3: search();
	   break;
   case 4: custcreate();
	   break;
   case 5: modsubmenu();
	   break;
   case 6: exit(0);
	   break;
   default: cout<<" wrong choice!!";
  }
  gotoxy(35,20);
  cout<<" Do you wish to continue? (y,n) : ";
  gotoxy(72,20);
  cin>>chr;
}while(chr=='y');
}

void main()
{
menu();
getch();
}









































