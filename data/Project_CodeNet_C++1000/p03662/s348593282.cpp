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
	vector<int> vec[100005]{};
	int n;
int black;
int white;
int can;
int p[100005];
int len;
int path[100005];
int pp[100005];
int cnt;
int r,s;

void ne(int a,int d){
p[a]=1;

for(int j=0;j<vec[a].size();j++){
if(p[vec[a][j]]==0){
	if(vec[a][j]==n){
can=1;
p[n]=1;
len=d+1;
path[len]=n;
path[d]=a;
return ;
	}
	if(can) break;
ne(vec[a][j],d+1);
}
}

if(can && path[d]==0 ){
	path[d]=a;
}

}

void count(int k){
for(int i=0;i<vec[k].size();i++){
if(pp[vec[k][i]]==0 &&vec[k][i]!=r && vec[k][i]!=s){
cnt++;
pp[vec[k][i]]=1;
count(vec[k][i]);
}
}
}






int main() {
black=0;
white=0;
can=0;
len=-1;
cnt=1;
	cin>>n;

rep(i, n){
	p[i]=0;
	pp[i]=0;
	path[i]=0;
}
path[0]=0;

rep(i, n-1){
	int a,b;
	cin>>a>>b;
	vec[a].push_back(b);
	vec[b].push_back(a);
}

ne(1,0);

r=path[len/2];
s=path[len/2+1];

int fenek=0;
int snuke=0;
count(r);
fenek=cnt;
cnt=1;
count(s);
snuke=cnt;

if(fenek>snuke){
	cout<<"Fennec"<<endl;
}
else{cout<<"Snuke"<<endl;}
return 0;




}



