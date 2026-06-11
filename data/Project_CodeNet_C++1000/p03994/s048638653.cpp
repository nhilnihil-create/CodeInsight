#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main() {
	string s; int K;
	cin >> s >> K;
	for (int i = 0; i < s.size(); i++) {
		int p = 'z' - s[i] + 1;
		if (s[i] == 'a')continue;
		else if (p <= K) {
			s[i] = 'a';
			K -= p;
		}
		else if (p >= K)continue;
	}
	if (K != 0) {
		int p = s.back() - 'a';
		p += K;
		p %= 26;
		s.back() = 'a' + p;
	}
	cout << s << endl;
}