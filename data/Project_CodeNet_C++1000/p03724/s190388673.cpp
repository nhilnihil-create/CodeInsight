#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<29;

int main() {
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }

    bool ok=true;
    for( auto i = mp.begin(); i != mp.end() ; ++i ) {
        int x=i->second;
        if(x%2==1) ok=false;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}