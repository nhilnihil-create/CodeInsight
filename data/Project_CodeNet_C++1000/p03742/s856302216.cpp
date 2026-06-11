#include<iostream>
using namespace std;
/*
bool sg[5][5]={{0,0,1,1,1},
               {0,0,0,1,1},
               {1,0,0,0,1},
               {1,1,0,0,0},
               {1,1,1,0,0}};
      */
int main()
{
    long long x,y;
    cin>>x>>y;
    if(x>y)swap(x,y);
    if(y-x>1)cout<<"Alice"<<endl;
    else cout<<"Brown"<<endl;

}