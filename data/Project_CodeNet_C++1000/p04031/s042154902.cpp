#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main(){
    int N; cin >> N;
    vector<int> v(N);
    rep(i,N){
        int a; cin >> a;
        v[i] = a;
    }

    ll res = (1LL<<60);
    for(int a=-100;a<=100;a++){
        ll sum = 0;
        rep(i,N){
            sum+=(v[i]-a)*(v[i]-a);
        }
        res = min(res,sum);
    }

    cout << res << endl;
}