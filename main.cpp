#include <iostream>
#include <time.h>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;
int c=0;
char L='1';
string id;
void hard(void);
void login(void);
void admin(void);
void welcome(void);
void test(void);
void result(void);
int main()
{
  login();
    system("cls");
       return 0;
}
                                                                                      //Login Function
void login(void)
{
    string pass,pas;
    int a=-1,b=-1;
    ifstream abc("panel.txt");
     if (abc.is_open())
  {
cout<<"Enter user ID \n";
    cin>>id;
    int x=id.size();
    cout<<"Enter Password \n";
    cin>>pass;
    int y=pass.size();
    while ( getline (abc,pas ))
    {
    a=pas.find(id);
    b=pas.find(pass);
    if(a==0)
    break;
    }
  int i=pas.find(' ');
    if(a==0&&b!=-1&&a!=b&&x==9||x==10&&y>4)
    {
        if(i==9)
        {
           abc.close();
        welcome();
        }
        if(i==10)
        {
            abc.close();
            admin();
        }
    }
      else
          {
           cout<<"\nInvalid User ID or Password\n";
           for(int i=0;i<3;i++)
           Beep(900,900);
           system("cls");
        login();
          }
}

  }
                                                                                      //Welcome Function


void welcome(void)
{
    system("cls");
    cout<<"Welcome to the CAT\nPlease Press any key to start the test. . . ";
    getche();
    system("cls");
    test();
       cout<<"Total Marks: "<<c;
       getche();

}
                                                                                      // Test Function for easy level questions

void test(void)
{
         here:
    if(L<='9')
    {
char x,y;
    string line,question,ans,no;
      int sp=0,a,b=0,i,q;
  ifstream myfile ("easy.txt");
   if (myfile.is_open())
  {
    while ( getline (myfile,line ))
    {
    if(L==line[1])
{
a=line.size();
 q=line.find('?');
 question=line.substr(1,q);
       cout<<question;
         cout<<endl;
         q=q+2;
         ans=line.substr(q,a);
         cout<<ans<<endl;
         break;
               }
    }
         clock_t start = clock();
    while ( ! _kbhit() ) //Check for keyboard hit
    {
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= 5)  //Check if 2 sec timer expired or not
        {
            system("cls");
            cout << "Time was expired." << endl;
            Beep(900,900);
            L=L+1;
            goto here;
                         //goto next question
            start = clock();                            //Set new timer
        }
    }
         x=getche();
          system("cls");
         y=line[0];
         if(x==y)
         {
            c=c+1;
            L=L+1;
            hard();
         }
            if(x!=y)
            {
                Beep(900,900);
          L=L+1;
           test();
            }
      }
        myfile.close();
result();
}
 }
void result(void)
{
    ofstream abc("results.txt",std::ios_base::app);
    if(abc.is_open())
    {
        abc<<endl<<id<<" ";
        abc<<c;
    }
}

                                                                                       //admin Function


void admin (void)
{
    string search,s;
    ifstream ab("results.txt");
    cout<<"Welcome to admin panel \n";
        here:
    cout<<"\nPlease Enter Roll. to Search Results:\n ";
    cin>>search;
    if(ab.is_open())
{
int a;
    while ( getline (ab,s ))
    {
    a=s.find(search);
    if(a==0)
       break;
    }
     if(a==-1)
       {
             cout<<"\nWrong id";
             goto here;
       }

        system("cls");
    if(a==0)
      cout<<"\n"<<s;
}
      getche();
      main();
}

                                                                                      // Function for hard level questions
void hard(void)
{
       here:
       if(L<='10')
    {
    char x,y;
    string line,question,ans,no;
      int sp=0,a,b=0,i,q;
  ifstream myfile ("hard.txt");
   if (myfile.is_open())
  {
    while ( getline (myfile,line ))
    {
   i=line.find(L);
    if(i>-1)
{
a=line.size();
 q=line.find('?');
 question=line.substr(1,q);
       cout<<question;
         cout<<endl;
         q=q+2;
         ans=line.substr(q,a);
         cout<<ans<<endl;
         break;
               }
    }
         clock_t start = clock();
    while ( ! _kbhit() ) //Check for keyboard hit
    {
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= 5)  //Check if 2 sec timer expired or not
        {
            system("cls");
            cout << "Time was expired." << endl;
            L=L+1;
            goto here;
                         //goto next question
            start = clock();                            //Set new timer
        }
    }
         x=getche();
          system("cls");
         y=line[0];
         if(x==y)
         {
            c=c+1;
            L=L+1;
            hard();
         }
            if(x!=y)
            {
                Beep(900,900);
          L=L+1;
            test();
            }
      }
        myfile.close();
}
}


