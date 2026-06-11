#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main(){
    int N,T; cin >> N >> T;
    vector<int> t(N);
    rep(i,N) cin >> t[i];

    ll l=0,r=0;
    bool on = false;
    ll res = 0;
    rep(i,N){
        if(t[i]<=r) on = true;
        else on = false;

        if(!on){
            res += r-l;
            l=t[i]; r=t[i]+T;
            on = true;
        }else{
            r=t[i]+T;
        }
    }
    res += r-l;
    cout << res << endl;
}