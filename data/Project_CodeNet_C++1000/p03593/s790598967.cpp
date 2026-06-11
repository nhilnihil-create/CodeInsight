//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>

using namespace std;
using ll=long long;
using intpair=pair<int,int>;
using intpv=vector<intpair>;
using llpair=pair<ll,ll>;
using llpv=vector<llpair>;
using intvec=vector<int>;
using llvec=vector<ll>;
using intq=queue<int>;
using llq=queue<ll>;
using intmat=vector<intvec>;
using llmat=vector<llvec>;
using pairmat=vector<llpv>;

template<typename T>
using matrix=vector<vector<T>>;
template<typename T>
using pque=priority_queue<T>;
template<typename T>
using lpque=priority_queue<T,vector<T>,greater<T>>;

#define PI 3.141592653589793
#define INTINF 1<<30
#define LLINF 1LL<<60
#define MPRIME 1000000007
#define MPRIME9 998244353

#define pushb push_back
#define fi first
#define se second

#define setpr fixed<<setprecision(15)
#define all(name) name.begin(),name.end()
#define rall(name) name.rbegin(),name.rend()
#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())
#define init(v,size) v.resize(size); for(auto &a__: v) cin>>a__
#define matin(mat,H,W) for(int i__=0; i__<H; i__++)for(int j__=0; j__<W; j__++) cin>>mat[i__][j__]
#define out(n) cout<<n<<endl

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline void outmat(T& a, int y, int x) {
	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

ll GCD(ll a, ll b) { //最大公約数
	if(a==0||b==0) return 0;
	if(a<b) swap(a,b);
	ll tmp = a%b;
	while(tmp!=0) {
		a = b;
		b = tmp;
		tmp = a%b;
	}
	return b;
}

ll binpow(ll a, ll ex, ll p) { //繰り返し二乗法
	ll result=1;
	while(ex>0) {
		if(ex&1) result=result*a%p;
		ex>>=1;
		a=a*a%p;
	}
	return result;
}

ll Fact(ll x, ll p) { //階乗
	ll f=1;
	for(ll i=2; i<=x; i++) {
		f*=i;
		f%=p;
	}
	return f;
}

ll nPr(ll n, ll r) {
	if(n<r) return 0;

	ll result=1LL;
	for(ll i=0; i<r; i++) result*=n-i;
	return result;
}

ll nPrP(ll n, ll r, ll p) { // mod pにおけるnPr
	if(n<r) return 0;

	ll result=1LL;
	for(int i=0; i<r; i++) {
		result*=n-i;
		result%=p;
	}
	return result;
}

ll nCr(ll n, ll r) {
	if (n == r) { return 1; }
	if (r > n) { return 0; }

	if (r > n / 2) { r = n - r; }

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return (ll)result;
}

int DigitNum(ll n) { //桁数
	int digit=0;
	ll div=1LL;
	while(n/div) {
		digit++;
		div*=10;
	}
	return digit;
}

bool Palind(string s) { //回文判定
	return s == string(s.rbegin(), s.rend());
}


int H,W;
int alp[26];

void input() {
	cin>>H>>W;
	for(int i=0; i<H; i++)for(int j=0; j<W; j++) {
		char ch; cin>>ch;
		alp[ch-'a']++;
	}
}

void solve() {
	int c4=H/2*(W/2), c2=H%2*W/2+W%2*H/2, c1=H%2*W%2;
	for(int i=0; i<26; i++) {
		if(alp[i]%2) {
			if(c1) {
				alp[i]--;
				c1--;
			}
			else {
				cout<<"No"<<endl;
				return;
			}
		}

		int a4=alp[i]/4;
		alp[i]-=min(a4,c4)*4;
		c4=max(c4-a4,0);

		int a2=alp[i]/2;
		alp[i]-=min(a2,c2)*2;
		c2=max(c2-a2,0);

		if(alp[i]) {
			cout<<"No"<<endl;
			return;
		}
	}

	cout<<"Yes"<<endl;
}

int main() {
	while(1) {
		input();
		solve();
		break;
	}
}
