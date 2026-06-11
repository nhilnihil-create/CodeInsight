//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>=0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;

int N,p[100010],ret;

int main(){
    I(N);
    REP(i,N) { I(p[i]); p[i]--; }
    bool flag = (p[0]==0);
    FOR(i,1,N){
        if(flag) {
            swap(p[i],p[i-1]);
            ret++;
            flag = false;
        } else {
            flag = (p[i]==i);
        }
    }
    cout << ret + flag << endl;
}
