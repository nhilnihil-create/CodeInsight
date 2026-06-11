#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,p,q,x,c1,c2,c3;
    ll n,m,z;
    ll v1[10],v2[10],v3[10];
     v1[0]=1;v1[1]=3;v1[2]=5;v1[3]=7;v1[4]=8;v1[5]=10;v1[6]=12;
     v2[0]=4;v2[1]=6;v2[2]=9;v2[3]=11;
     v3[0]=2;
    cin>>n>>m;
    c1=0;
    for(ll i=0; i<7; i++)
    {
       if(v1[i]==n) c1++;
       if(v1[i]==m) c1++;
    }
    c2=0;
    for(ll i=0; i<4; i++)
    {
       if(v2[i]==n) c2++;
       if(v2[i]==m) c2++;
    }
    c3=0;
    for(ll i=0; i<1; i++)
    {
       if(v3[i]==n) c3++;
       if(v3[i]==m) c3++;
    }


    if(c1==2 || c2==2 || c3==2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}






