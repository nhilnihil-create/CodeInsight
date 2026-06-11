#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+3;
//string s,p;
//vector<int>v;
//map<int,int>mp;

int main()
{
    ft
    ll t,i,j,n,m,l,r,a[5];
    for(i=0;i<3;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3);
    if((a[0]+a[1])==a[2])
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}

