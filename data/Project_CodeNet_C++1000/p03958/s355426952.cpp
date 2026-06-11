#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int k,t;
    cin>>k>>t;
    vector<int> a(t);
    rep(i,t)cin>>a[i];
    sort(a.begin(),a.end());
    if(k-a[t-1]>=a[t-1])
    {
        cout<<0;
    }
    else
    {
        cout<<2*a[t-1]-k-1;
    }
    
}
