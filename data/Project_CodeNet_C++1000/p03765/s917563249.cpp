#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

string s, t;
Int q;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s >> t >> q;
	vector<Int> a(s.size()+1);
	vector<Int> b(t.size()+1);
	for(size_t i=0; i<s.size(); ++i)
		a[i+1] = s[i] == 'B' ? 2 : 1;
	for(size_t i=0; i<t.size(); ++i)
		b[i+1] = t[i] == 'B' ? 2 : 1;
	for(size_t i=1; i<a.size(); ++i)
		a[i] += a[i-1];
	for(size_t i=1; i<b.size(); ++i)
		b[i] += b[i-1];
	while(q--){
		Int x, y, z, w;
		cin >> x >> y >> z >> w;
		Int t = a[y] - a[x-1];
		Int s = b[w] - b[z-1];
		cout << ((t - s) % 3 == 0 ? "YES" : "NO") << "\n";
	}
}