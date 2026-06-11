#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll x,y;
    cin>>x>>y;
    
    ll res=1LL<<60;
    if(x<=y) res=min(res,y-x);
    if(-x<=y) res=min(res,y+x+1);
    if(x<=-y) res=min(res,-y-x+1);
    if(-x<=-y) res=min(res,-y+x+2);

    cout<<res<<endl;
}