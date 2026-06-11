#include <bits/stdc++.h>
using namespace std;
int main(){
	string s, t; cin >> s >> t;
	int lens = s.size(), lent = t.size();
	vector<int> pref_s(lens + 1, 0), pref_t(lent + 1, 0);
	for(int i = 0; i < lens; i++){
		pref_s[i + 1] = pref_s[i] + (s[i] == 'A');
	}
	for(int i = 0; i < lent; i++){
		pref_t[i + 1] = pref_t[i] + (t[i] == 'A');
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int sA = pref_s[b] - pref_s[a - 1], sB = b - a + 1 - sA;
		int tA = pref_t[d] - pref_t[c - 1], tB = d - c + 1 - tA;
		sA %= 3; sB %= 3;
		tA %= 3; tB %= 3;
		bool can = false;
		int nA = sA, nB = sB;
		for(int k = 0; k < 4; k++){
			nA += 2; nA %= 3;
			nB += 2; nB %= 3;
			if(nA == tA && nB == tB){
				can = true;
			}
		}
		if(can) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
