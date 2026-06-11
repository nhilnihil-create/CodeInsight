#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

ll g(ll a, ll b){
	if(a < b) return g(b,a);
	if(a==0) return b;
	if(b==0) return a;
	else if(a%b==0) return b;
	else return g(b,a%b);
}

int main(){
	int n;
	ll k;
	cin >>n >> k;
	ll a[n];
	ll max1=0;
	FOR(i,n) {
		cin >> a[i];
		max1=max(max1,a[i]);
	}
	ll gcd=a[0];
	for(ll j=1;j<n;j++){
		gcd=g(gcd,a[j]);
	}
	//cout << gcd;
	if(k%gcd==0 && max1 >=k) cout << "POSSIBLE";
	else cout << "IMPOSSIBLE";


	return 0;
}