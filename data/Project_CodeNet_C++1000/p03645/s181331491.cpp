#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n,m;
    cin>>n >> m;
    vector<vector<int>> g(n+1);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,g[1].size()){
        int dex=g[1][i];
        rep(k,g[dex].size()){
            if(g[dex][k]==n){
                cout<<"POSSIBLE"<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
