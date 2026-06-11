#include <bits/stdc++.h>
using namespace std;
const int MN = 100100;
int v[MN],w[MN];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	string s,t;
	cin >> s >> t;
	int rs = 0;
	for(int i=0;i<s.size();i++) {
		v[i] = rs;
		rs += s[i]-'A'+1;
	}
	v[s.size()] = rs;
	rs = 0;
	for(int i=0;i<t.size();i++) {
		w[i] = rs;
		rs += t[i]-'A'+1;
	}
	w[t.size()] = rs;
	int q;
	cin >> q;
	while(q--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--;b--;c--;d--;
		int ss = v[b+1]-v[a];
		int ts = w[d+1]-w[c];
		bool po = ((ts-ss)%3==0);
		cout << (po?"YES":"NO") << '\n';
	}
}