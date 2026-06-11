#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{ int a,b,c;
int sum1,sum2,sum3;
cin>>a>>b>>c;
sum1=a+b;
sum2=a+c;
sum3=b+c;
 if(sum1==c)
    cout<<"Yes"<<endl;

 else if( sum2==b )
    cout<<"Yes"<<endl;

else if (sum3==a)
    cout<<"Yes";

else
    cout<<"No";
    return 0;
}

