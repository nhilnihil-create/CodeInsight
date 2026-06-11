#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    ll c = 1LL*a - 1LL*b;
    int ok = 1e9;
    int ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        ll cnt = 0;
        rep(i, n){
            ll goal = 1LL*h[i] - 1LL*b*mid;
            if(goal > 0) cnt += (goal + c - 1) / c;
        }
        if(cnt <= mid) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}