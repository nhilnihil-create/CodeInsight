#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_d>
問題文============================================================
 非負整数専門店「せいすうや」には、N 個の非負整数が売られています。
 i 個目の非負整数は Ai で、その価値は Bi です。 価値の異なる同じ非負整数が複数売られていることもあります。
 
 高橋君は、「せいすうや」でいくつかの整数を買うことにしました。
 高橋君は、買う整数たちの bitwise or が K 以下になるような 任意の組み合わせで、整数を買うことができます。
 高橋君は、買った整数たちの価値の総和をできるだけ大きくしたいです。
 
 高橋君が達成できる、価値の総和の最大値を求めてください。
 ただし、bitwise or とは、ビットごとの論理和を表します。
=================================================================

解説=============================================================

================================================================
*/
ll solve(){
    ll ret = 0;
    ll N,K; cin >> N >> K;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];
    for(int i = 0; i < N;i++) if(K == (K|A[i])) ret += B[i];
    for(ll i = 1; i <= K; i<<= 1){
        if(!(i&K)) continue;
        ll nK = (K^i) | (i-1);
        ll T = 0;
        for(int j = 0; j < N;j++){
            if(nK != (nK|A[j])) continue;
            T += B[j];
        }
        ret = max(ret,T);
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
