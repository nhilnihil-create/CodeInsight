#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 3e9;

string s, t;
int pref1[100005], pref2[100005];

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> s >> t;
	s = '*' + s;
	t = '*' + t;
	for(int i = 1; i < s.length(); i++) pref1[i] = (pref1[i - 1] + ((s[i] == 'A') ? 1 : -1));
	for(int i = 1; i < t.length(); i++) pref2[i] = (pref2[i - 1] + ((t[i] == 'A') ? 1 : -1));
	int q;
	cin >> q;
	while(q--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(!((pref1[b] - pref1[a - 1] - pref2[d] + pref2[c - 1] + oo) % 3)) cout << "YES\n";
		else cout << "NO\n";
	}
}
