#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	printf("%s %s %s\n", s.substr(0, 5).c_str(), s.substr(6, 7).c_str(), s.substr(14, 5).c_str());
	
	return 0;
}