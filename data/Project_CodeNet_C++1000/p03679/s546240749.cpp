#include<bits/stdc++.h>
#define   ll          long long int
#define   sz          200010
#define   sc(a)       scanf("%lld",&a)
#define   sc2(a,b)    scanf("%lld %lld",&a,&b)
#define   py          printf("Yes\n")
#define   pn          printf("No\n")
using namespace std;


ll num[sz];



int main()
{


    ll x,a,b,n,m,p,k,d;

    cin>>x>>a>>b;
    a=-a;
    p=a+b;
   // cout<<p<<endl;


    if(p<=0)cout<<"delicious"<<endl;
    else if(p<=x)cout<<"safe"<<endl;
    else
        cout<<"dangerous"<<endl;




    return 0;
}

