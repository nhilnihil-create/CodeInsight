#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i=0;i<n;++i)
#define FOR(i,j,n) for(ll i=j;i<n;++i)
#define MOD (1e9 + 7)

int main(void){
    ll N, M;
    cin >> N >> M;
    ll B[N], R[N];
    REP(i,N){B[i] = 1; R[i] = 0;}
    R[0] = 1;
    ll x, y;
    REP(i,M){
        cin >> x >> y;
        B[x-1] -= 1;
        B[y-1] += 1;
        if(R[x-1]==1){
            R[y-1] = 1;
            if(B[x-1]==0){
                R[x-1] = 0;
            }
        }
    }
    ll res = 0;
    REP(i,N){
        if(B[i]>0 && R[i]==1){
            res += 1;
        }
    }
    cout << res << endl;
}