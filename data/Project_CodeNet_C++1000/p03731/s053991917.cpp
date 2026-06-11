#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9+7;
int32_t main()
{
    int n,t;
    cin>>n>>t;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    int res=0;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]>t)res+=t;
        else res+=v[i]-v[i-1];
    }
    res+=t;
    cout<<res<<endl;

    return 0;
}
