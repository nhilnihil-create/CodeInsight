#include<iostream>
using namespace std;
int main()
{
   int a,b,c,sum=0;
   cin>>a>>b>>c;
   if(a==b&&b==c)
    {
        cout<<sum+1<<endl;
    }
    else if(a==b||b==c||c==a)
    {
        cout<<sum+2<<endl;
    }
    else
    {
        cout<<sum+3<<endl;
    }


    return 0;
}
