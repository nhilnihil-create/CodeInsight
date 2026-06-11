#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (ll)(n); ++i)
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	string s; cin >> s;
	int n=s.size();
	rep(i,n) {
		for(int j=i+1;j<n;j++) {
			if(s[i]==s[j]) {
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;
}