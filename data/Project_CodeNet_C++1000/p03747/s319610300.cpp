#include<bits/stdc++.h>
#define rep(i,n) for(long long i=0;i<(n);i++)
#define ll long long
using namespace std;
int main(){
    ll L,N,T;
    cin >> N >> L >> T;
    vector<ll> X(N);
    vector<int> W(N);
    rep(i,N) cin >> X[i] >> W[i];
    vector<ll> tmp(N); ll count = 0;
    rep(i,N){
        ll d = (W[i] == 1) ? (X[i] + T) : (X[i] - T)%L + L;
        d %= L; 
        tmp[i] = d;
    }
    /*
    rep(i,N){
        ll d = (W[i] == 1) ? (X[i] + T) : (X[i] - T);
        if(W[i] == 1) count += d/L; 
        else {if(d < 0) count += -1 + d/L;};
    }
    count = (count % N + N)%N;
*/    
    for (int i = 0; i < N; ++i) {
        if (W[i] == 1) count -= (T - (L - X[i]) + L) / L;
        else count += (T - (X[i] + 1) + L) / L;
    }
    
    sort(tmp.begin(), tmp.end());
    count = (count % N + N) % N;
    //cout << "count = " << count << endl;
    vector<long long> res(N);
    for (int i = 0; i < N; ++i) res[(i+count)%N] = tmp[i];
    for (int i = 0; i < N; ++i) cout << res[i] << endl;
    //for (int i = 0; i < N; ++i) cout << tmp[(i+count)%N] << endl;

    return 0;
}