#include <cstdlib>
#include <iostream>
#include <fstream>
#define abs(x) (x>0?x:-x)
const int P=1000;
const int Q=20;
const int R=20;
using namespace std;

ifstream fin("rect-2.in");
ofstream fout("rect-2.out");

int p,M,N,kind=0;
int k[R][2];
class square
{
      public:
             int x,y;
};

square b[R];

class stack
{
      public:
             square a[P],*T,*B;
             int top;
             bool Empt,Full;
};

stack s;

int ccc(int x,int y)
{   int i;
    int op=abs(x);
    if(op<abs(y))
    {
            op=abs(y);
    }
    for(i=op;i>0;i--)
    {
                     if(abs(x)%i==0 && abs(y)%i==0)
                     return i;
    }
}
void makes()
{
     for(int i=0;i<P;i++)
     {
         s.a[i].x=0;
         s.a[i].y=0;
     }
     s.T=&s.a[0];
     s.B=&s.a[0];
     s.top=0;
     s.Empt=true;
     s.Full=false;
}

void push(int x,int y)
{
     if(s.Full==true)
     {
                     cerr<<"stack is full"<<endl;
     }
     else
     {
         s.a[s.top].x=x;
         s.a[s.top++].y=y;
         s.T=&s.a[s.top];
         s.Empt=false;
         if(s.top==P)
         s.Full=true;
     }
}
void pop()
{
     if(s.Empt==true)
     {
                     cerr<<"stack is empty"<<endl;
     }
     else
     {
         s.a[--s.top].x=0;
         s.a[s.top].y=0;
         s.T=&s.a[s.top];
         s.Full=false;
         if(s.top==0)
         s.Empt=true;
     }
}

void outp()
     {    int m=s.top;
          for(int i=0;i<m;i++)
          {
                  cout<<s.a[i].x<<" "<<s.a[i].y<<endl;
                  //fout<<s.a[i].x<<" "<<s.a[i].y<<endl;
          }
          cout<<endl;
          fout<<endl;
     }


void in()
{
     for(int i=0;i<p;i++)
     {
                     fin>>b[i].x>>b[i].y;
                     //cout<<b[i].x<<" "<<b[i].y<<endl;
     }
}

void xl()
{
     for(int i=0;i<p-1;i++)
     {
                        k[i][0]=(b[i].y-b[i+1].y)/ccc((b[i].y-b[i+1].y),(b[i].x-b[i+1].x));
                        k[i][1]=-(b[i].x-b[i+1].x)/ccc((b[i].y-b[i+1].y),(b[i].x-b[i+1].x));
                        //cout<<k[i][0]<<" "<<k[i][1]<<"  "<<ccc((b[i].y-b[i+1].y),(b[i].x-b[i+1].x))<<endl;
     }
}
void f(int i,int x,int y)
{    push(x,y);
     //cout<<x<<" "<<y<<" "<<i<<endl;
     int k3,a=1;
     if(i==p-1) {
        if (x==b[p-1].x && y==b[p-1].y)
             {kind++;
             outp();
             pop();
             return;
             }
        else {
             pop();
             return;
        }
     }
     while(x+a*k[i][0]>=0 && x+a*k[i][0]<=M && 
                  y+a*k[i][1]>=0 && y+a*k[i][1]<=N)
                  {
                              f(i+1,x+a*k[i][0],y+a*k[i][1]);   
                              a++;
                  }
     a=1;
     while(x-a*k[i][0]>=0 && x-a*k[i][0]<=M &&
             y-a*k[i][1]>=0 && y-a*k[i][1]<=N)
             {
                            f(i+1,x-a*k[i][0],y-a*k[i][1]);
                            a++;
             }
     pop();
     
}

int main(int argc, char *argv[])
{   makes();
    //cout<<"input points m,n"<<endl;
    M=10, N=10;
    fin>>p>>M>>N;
    in();
    xl();
    f(0,b[0].x,b[0].y);
    if(kind!=0)
    {
    cout<<"共"<<kind<<"种方法"<<endl;
    //fout<<endl<<kind<<"种方法" <<endl;
    if(kind==1)
    {
               cout<<"是“形独”"<<endl;
    }    
    else
    {
         cout<<"不是“形独”"<<endl; 
    }}
    else
    {
        cout<<"没有方法"<<endl; 
    }
    system("PAUSE");
    return 0;
}
