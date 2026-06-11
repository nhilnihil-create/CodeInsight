#include "bits/stdc++.h"

#define rep(a,b) for(int a = 0;a < b;a++)
#define REP(i, x, n) for(int i = x; i < n; i++)
#define P(a) cout << a << endl
#define mp(a,b) make_pair(a,b)
#define ssort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define vP(v) for(int i = 0;i < v.size();i++){cout << v[i];if(i != v.size()-1)cout << endl;}
#define vcin(v,n) rep(i,n){int a;cin >> a;v.pb(a);}

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { 1, -1 , 0 , 0 };
int dy[] = { 0,  0,  1, -1 };
ll MOD = 1000000007;

long long stoi(string str) {
	long long ret;
	stringstream ss; ss << str;
	ss >> ret;
	return ret;
}

ull gcd(ull a, ull b) {
	if (b > a)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
void solve() {
	int n;
	cin >> n;
	vector<int> v;
	int count = 0;
	rep(i, n) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	rep(i, n-1) {
		if (v[i] == i+1) {
			swap(v[i], v[i + 1]);
			count++;
		}
	}
	if (v[n - 1] == n) {
		swap(v[n - 2], v[n - 1]);
		count++;
	}
	P(count);
}

int main() {
	solve();
	return 0;
}
