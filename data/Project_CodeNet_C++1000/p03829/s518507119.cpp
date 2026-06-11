#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    vll x(n);
    rep(i,n) cin >> x[i];
    ll cost=0;
    for(int i=0;i<n-1;i++){
        cost+=min(a*(x[i+1]-x[i]),b);
    }
    cout << cost << endl;
}