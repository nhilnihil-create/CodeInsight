#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bits/stdc++.h>
#include <utility>
#include <iomanip>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

const ll MAX = 200010;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// NのP乗をMで割った余りを返す
ll pow_mod(ll n,ll k,ll m){
  if(k==0){
    return 1;
  }else if(k%2==1){
    return pow_mod(n,k-1,m)*n%m;
  }else{
    ll t=pow_mod(n,k/2,m);
    return (t*t)%m;
  }
}

//(10*9*8)/(3*2*1);
//10*9*8 -> ansMul
//3*2*1 -> ansDiv
long long calcComb(ll a, ll b) {
	if (b > a - b) return calcComb(a, a - b);


	ll ansMul = 1;
	ll ansDiv = 1;
	for (int i = 0; i < b; i++)
	{
		ansMul *= (a - i);
		ansDiv *= (i + 1);
		ansMul %= MOD;
		ansDiv %= MOD;
	}
	//ansMul / ansDivをやりたい
	//ansDivの逆元を使って求めよう！

	ll ans = ansMul * pow_mod(ansDiv,MOD - 2,MOD);
	return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll H,W,A,B;
  cin >> H >> W >> A >> B;
  ll ans=0;
  COMinit();
  for(int i=1;i<=H-A;i++){
    ans+=(COM(i-1+B-1,i-1)*COM(H+W-B-i-1,H-i)%MOD);
    ans%=MOD;
  }
  cout << ans << endl;
  return 0;
}
