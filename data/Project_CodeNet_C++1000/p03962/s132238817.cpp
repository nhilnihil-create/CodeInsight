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
set<int>s;
int main()
{
    ft
    ll t,i,j,n,m,l,r;
    for(i=0;i<3;i++)
    {
        cin>>m;
        s.insert(m);
    }
    cout<<(int)s.size()<<"\n";
    return 0;
}

