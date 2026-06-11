#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string s;
string t;
int prefixS[N];
int prefixT[N];

int q;

int main() {
	cin >> s;
	cin >> t;
	fill(prefixS, prefixS + N, 0);
	fill(prefixT, prefixT + N, 0);
	for(int i = 0; i < s.length(); i++) {
		prefixS[i+1] = prefixS[i] + ((s[i] == 'A')? 1:2);
	}

	for(int i = 0; i < t.length(); i++) {
		prefixT[i+1] = prefixT[i] + ((t[i] == 'A')? 1:2);
	}

	cin >> q;

	int a, b, c, d;
	while(q--) {
		cin >> a >> b >> c >> d;
		if(((prefixS[b] - prefixS[a-1])-(prefixT[d] - prefixT[c-1]))%3) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}