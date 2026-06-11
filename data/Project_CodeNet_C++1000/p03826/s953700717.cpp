
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a , b , c , d;
    cin>>a>>b>>c>>d;
    long long ar1 , ar2 ;
    ar1=a*b;
    ar2=c*d;
    if (ar1<=ar2)
    {
        cout<<ar2<<endl;
    }
    else
    {
        cout<<ar1<<endl;
    }
}
