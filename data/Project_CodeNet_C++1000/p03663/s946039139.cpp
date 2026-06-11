#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MAX 510000
#define rrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define dcout cout<<fixed<<setprecision(15);

using namespace std;
typedef long long int  ll;
typedef pair<int, int> P;

constexpr int MOD = 1e9 + 7;
constexpr ll inf = 1LL << 60;

//lcm//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//a^n mod p//
ll modpow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;
  ll t = modpow(a, n / 2, p);
  return (t * t) % p;
}

//inversemod//
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
// 
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

// 
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//LARGE n
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

//radP
ll rad(ll u, ll p){
ll cnt=0;
	while(u%p==0){
		u/=p;
		cnt++;
	}
	return cnt;
}


////////////////////////////////////////////////////////////////////

int main() {

ll k=1;
int fin=0;
	for(int i=1;i<=10;i++){
if(i>=2) k*=10;
cout<<'?'<<" "<<k<<endl;
cout<<flush;
char q;
cin>>q;
if(q=='N') break;
if(i==10) fin=1;
	}


	if(fin){
		k=0;
for(int i=1;i<=10;i++){
 k=k*10+9;
cout<<'?'<<" "<<k<<endl;
cout<<flush;
char q;
cin>>q;
if(q=='Y'){
	if(i==1) {cout<<'!'<<" "<<1<<endl;
cout<<flush;
return 0;}
cout<<'!'<<" "<<(k+1)/10<<endl;
cout<<flush;
return 0;
}
}


	}


ll left=k/10;
ll right=k-1;
ll v=0;

for(int w=1;w<=40;w++){
	ll mid=(left+right)/2;
	v=mid;
	ll u=(ll)10000000000000/k;
	ll e=mid;
	e*=u;
	e+=u-1;
	cout<<'?'<<" "<<e<<endl;
cout<<flush;
char q;
cin>>q;
if(q=='Y') right=mid;
else left=mid;
}

if(v+1<k){
ll u=(ll)10000000000000/k;
ll y=v;
y*=u;
y+=u-1;
cout<<'?'<<" "<<y<<endl;
cout<<flush;
char q;
cin>>q;
if(q=='N') v++;
}


cout<<'!'<<" "<<v<<endl;
cout<<flush;

return 0;
}


