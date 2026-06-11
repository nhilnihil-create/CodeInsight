#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define Rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;
typedef long long int  ll;
typedef pair<int, int> P;

//cout << fixed << setprecision(10);//
//最小公倍数//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//べき//
ll squ(ll n, ll p, ll m){
	if(p==0) return 1;
	if(p%2==0){
		ll t=squ(n, p/2, m);
		return t*t%m;
	}
	return n*squ(n,p-1,m);
	
}


//逆元mod(mを法とするaの逆元)//
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

//Cmonp//
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//nが大

ll com(ll n,ll m){
    if(n<m || n<=0 ||m<0){
		return 0;
	}
	if( m==0 || n==m){
		return 1;
	}
	
	ll k=1;
	for(ll i=1;i<=m;i++){
       k*=(n-i+1); 
	   k%=MOD;
	   k*=modinv(i,MOD);
	   k%=MOD;
	}

	return k;
}


////////////////////////////////////////////////////////////////////


int main() {
ll n;
ll ma,mb;
cin>>n;
cin>>ma>>mb;

ll med[n+1][3];
for(ll i=0;i<=n;i++){
for(int j=0;j<=2;j++){
	if(i==0){med[i][j]=0;
	continue;}
	cin>>med[i][j];
}
}

ll ans=1000000;
ll dp[401][401][n+1];

for(int k=0;k<=n;k++){
	
	ll p=med[k][0];
		ll q=med[k][1];
		ll val=med[k][2];
	
for(ll i=0;i<=400;i++){
for(ll j=0;j<=400;j++){

if(i==0 && j==0 ){dp[i][j][k]=0;
continue;}
if(k==0){dp[i][j][k]=1000000;
continue;}
if(i>=p && j>=q){
	dp[i][j][k]=min(dp[i-p][j-q][k-1]+val,dp[i][j][k-1]);
	continue;
}
dp[i][j][k]=dp[i][j][k-1];

}

}
}


for(ll i=1;i<=400;i++){
for(ll j=1;j<=400;j++){
if(i/ma==j/mb && i%ma==0 && j%mb==0){
	ans=min(ans,dp[i][j][n]);
	
}
}
}



if(ans==1000000){cout<<-1<<endl;}
else {cout<<ans<<endl;}
return 0;


}


