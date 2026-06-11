#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}


int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    bool ok=false;
    rep(i,n){
        if(k==a[i]){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
        if(k<a[i]) ok=true;
    }

    if(!ok){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    int g=a[0];
    for(int i=1;i<n;i++){
        g=gcd(g,a[i]);
    }

    if(k%g==0) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}

