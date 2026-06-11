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
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        mp[a]+=b;
    }
    for(auto val:mp){
        if(val.second>=k){
            cout<<val.first<<endl;
            return 0;
        }
        else k-=val.second;
    }
    return 0;
}
