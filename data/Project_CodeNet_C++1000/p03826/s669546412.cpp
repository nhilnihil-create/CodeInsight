#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a,b,c,d,sum1,sum2;
 cin>>a>>b>>c>>d;
 sum1=a*b;
 sum2=c*d;
 if(sum1<sum2)
 cout<<sum2<<endl;
 else if(sum2<sum1)
 cout<<sum1<<endl;
 else if(sum1==sum2) 
 cout<<sum1<<endl;
} 