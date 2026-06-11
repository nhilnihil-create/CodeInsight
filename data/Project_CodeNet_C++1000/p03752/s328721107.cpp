#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#define int long long
typedef long long ll;
using namespace std;

ll N, K, A[15], M[16], mincount=100000000000;

void dfs(ll id, ll k, vector<ll> v){
    if(k>K) return;
    if(id==N){
        if(k!=K) return;
        ll ms[N+1];
        ll count=0;
        for(ll i=0;i<N+1;i++) ms[i] = M[i];
        for(ll i=0;i<v.size();i++) {
            if(v[i]==1) {
                if(A[i]-ms[i]-1<0) {
                    count+= ms[i]+1-A[i];
                    for(ll j=i+1;j<N+1;j++) ms[j] = max(ms[i]+1, ms[j]);
                }
            }
        }
        mincount = min(mincount, count);
        /*
        cout << maxcount;
        for(ll i=0;i<as.size();i++) cout << " " << as[i];
        cout << endl;
        */
        return;
    }
    v[id] = 0;
    dfs(id+1, k, v);
    v[id] = 1;
    dfs(id+1, k+1, v);
}

signed main(){
    cin >> N >> K;
    ll mh = 0;
    for(ll i=0;i<N;i++) {
        M[i] = mh;
        cin >> A[i];
        mh = max(mh, A[i]);
    }

    vector<ll> vemp;
    vemp.resize(N);
    dfs(0, 0, vemp);
    cout << mincount << endl;
    return 0;
}