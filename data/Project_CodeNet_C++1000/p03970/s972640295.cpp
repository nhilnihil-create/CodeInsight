#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)

int main() {
	string s; cin >> s;
	string t="CODEFESTIVAL2016";
	int count = 0;
	rep(i,16) {
		if(s[i]!=t[i]) count++;
	}
	cout << count << endl;
}