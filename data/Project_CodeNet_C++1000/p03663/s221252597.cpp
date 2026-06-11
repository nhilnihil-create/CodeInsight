#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

typedef long long ll;
typedef pair<ll,ll> P;

char c;
ll n;

void rian(ll a){
	string aa = to_string(a);
	string bb = to_string(n);
	if((a < n && aa < bb) || (a > n && aa > bb))c = 'Y';
	else c = 'N';
	cout << c << endl;
}

void ixmel(ll l) {
	ll r = l * 10;
	while(r - l > 1){
		ll mid = (l + r) / 2;		
		cout << "? " << mid * 10 << endl;
		cin >> c;
//		rian(mid * 10);
		if(c == 'Y')r = mid;
		else l = mid;
	}
	cout << "! " << r << endl;
}

void valuna() {
	ll out = 100000000;
	while(1){
		cout << "? " << out << endl;
		cin >> c;
//		rian(out);
		if(c == 'Y'){
			ixmel(out);
			return;
		}
		out /= 10;
	}
}

void seica(){
	ll out = 2;
	REP(i, 10){
		cout << "? " << out << endl;
		cin >> c;
//		rian(out);
		if(c == 'Y'){
			cout << "! " << out / 2 << endl;
			return;
		}
		out *= 10;
	}
}

int main(){
	
	cout << "? 1000000000" << endl;
	cin >> c;
//	rian(1000000000);
	if(c == 'Y')seica();
	else valuna();
	
	return 0;
}
