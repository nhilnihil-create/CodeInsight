#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){
    int n,m;cin>>n>>m;
    vector<string> a(n),b(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    //cout<<a[0]<<endl;
    rep(i,n){
        rep(j,n){
            if(a[i][j]!=b[0][0])continue;
            int ok = 1;
            rep(k,m){
                rep(l,m){
                    if(i+k>=n||j+l>=n||a[i+k][j+l]!=b[k][l]){
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}