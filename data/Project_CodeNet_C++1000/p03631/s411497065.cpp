#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,t,a,b,n,c,y,d,m,prev,sum,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       string s1=s;
       reverse(s.begin(),s.end());
       if(s==s1)cout<<"Yes";
       else cout<<"No";
    }
}