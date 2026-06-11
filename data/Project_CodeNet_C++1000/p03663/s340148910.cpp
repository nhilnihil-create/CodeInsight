#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#define int long long
using namespace std;

signed main() {
	int S = 999999999ll, G = 9999999990ll;//[S,G)
	while (G - S > 1) {
		int T = (S + G) / 2;
		string K = to_string(T);
		K += "555";
		cout << "?" << " " << K << endl;
		char i; cin >> i;
		if (i == 'N')S = T;
		else G = T;
	}
	string x = to_string(G);
	while (1) {
		if (x[x.size() - 1] != '0') { cout << "! " << x << endl; break; }
		int y = stoll(x);
		x.erase(--x.end());
		string u;
		for (int i = 0; i < x.size(); i++) {
			u += '9';
		}
		cout << "?" << " " << u << endl;
		char i; cin >> i;
		if (i == 'N') { cout << "! "<< x << "0" << endl; break; }
	}
}