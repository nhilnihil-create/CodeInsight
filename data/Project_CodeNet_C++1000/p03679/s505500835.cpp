#include <bits/stdc++.h>
using namespace std;
int main()
{
    long i,j,t,a,b,n,temp;
    t=1;
    // cin>>t;
    while(t--)
    {
       cin>>i>>a>>b;
       a=b-a;
       if(a>i)cout<<"dangerous";
       else if(a<=0)cout<<"delicious";
       else cout<<"safe";
    }
}