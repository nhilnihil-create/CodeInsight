#include<bits/stdc++.h>
using namespace std;

#define p_ary(ary,a,b,i) do { cout << "["; for (int i = a;i <= b;++i) cout << ary[i] << (b == i ? "]\n" : ", "); } while(0)
#define p_map(map,it) do {cout << "{";for (auto it = map.begin();;++it) {if (it == map.end()) {cout << "}\n";break;}else cout << "" << it->first << "=>" << it->second << ", ";}}while(0)

int main() {
	int n,cnt = 0,l = 0,r = 0;
	vector<int> len(200010,0),p[26];
	string a;
	map<char,bool> b;
	cin >> a;
	n = a.size();

	for (int i = n-1;i >= 0;--i) {
		if (!b[a[i]]) {
			b[a[i]] = true;
			cnt++;
		}
		if (cnt == 26) {
			cnt = 0;
			l++;
			b.clear();
		}
		len[i] = l;
	}
	len[n] = -1;len[n+1] = -1;

	for (int i = 0;i < n;++i) p[a[i]-'a'].push_back(i);
	for (int i = 0;i < 26;++i) p[i].push_back(n);

	for (int i = 0;i < l+1;++i) {
		for (int j = 0;j < 26;++j) {
			int c = *lower_bound(p[j].begin(),p[j].end(),r);
			if (len[r] > len[c+1]) {
				cout << (char)('a'+j);
				r = c+1;
				break;
			}
		}
	}
	cout << endl;
	return 0;
}