#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string s;
	cin >> s;
	ll n = s.size();
	vector<int> dict(26, 0);
	rep(i, n) {
		int id = s[i] - 'a';
		dict[id]++;
	}
	ll dup = 0;
	for(int i = 0;i < 26;i++){
		ll len = dict[i];
		if (len) {
			dup += len * (len - 1) / 2;
		}
	}
	ll sum = n * (n - 1) / 2 + 1;
	cout << sum - dup << endl;
	return 0;
}
