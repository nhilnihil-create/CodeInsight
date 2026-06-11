#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   long long color,ball,sum;
   cin>>ball>>color;
   sum=color*pow(color-1,ball-1);
   cout<<sum<<endl;
   return 0;
}
