#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i=0;i<n;++i)
#define FOR(i,j,n) for(ll i=j;i<n;++i)
#define MOD (1e9 + 7)

int main(void){
    ll N,M,K;
    cin >> N >> M >> K;
    ll mem[N*M+1];
    memset(mem,0,N*M+1);
    REP(i,N+1){
        REP(j,M+1){
            mem[i*M+j*N-2*i*j] = 1;
        }
    }
    if(mem[K]==1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
