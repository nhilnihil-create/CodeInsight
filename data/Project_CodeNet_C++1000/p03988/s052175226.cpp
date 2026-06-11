#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MOD 1000000007
#define MAX 510000
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//cout << fixed << setprecision(10);//
//最小公倍数//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

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
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//nが大

ll com(ll n,ll m){
	if(n<=0 || m<=0 || n==m){
		return 1;
	}
	if(n<m){
		return 0;
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

int n;
cin>>n;
int a[n];
for(int i=0;i<=n-1;i++){
cin>>a[i];
}

sort(a,a+n,greater<int>());
int k[201];
for(int i=1;i<=200;i++){
	k[i]=0;
}

int s;
if(a[0]%2){
s=(a[0]+1)/2;
for(int i=s;i<=a[0];i++){
	k[i]=2;
}
}

if(a[0]%2==0){
	s=a[0]/2;
	for(int i=s;i<=a[0];i++){
		if(i==s){k[s]=1;}
		else{k[i]=2;}
	}
}

for(int i=0;i<=n-1;i++){
if(a[i]<s){
	cout<<"Impossible"<<endl;
	return 0;}
	if(a[0]%2==0){
		int q=0;
		for(int k=0;k<=n-1;k++){
			if(a[k]==s) q++;
		}
		if(q>=2){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}

if(a[0]%2==1){
		int q=0;
		for(int k=0;k<=n-1;k++){
			if(a[k]==s) q++;
		}
		if(q>=3){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}

}

for(int i=1;i<=200;i++){
	if(k[i]){
		for(int j=0;j<=n-1;j++){
			if(a[j]==i){
				a[j]=0;
				k[i]--;
				break;
			}
		}
	}
if(k[i]){
		for(int j=0;j<=n-1;j++){
			if(a[j]==i){
				a[j]=0;
				k[i]--;
				break;
			}
		}
	}

}

for(int i=1;i<=200;i++){
	if(k[i]){
		cout<<"Impossible"<<endl;
		return 0;
	}
}

cout<<"Possible"<<endl;
return 0;



}
