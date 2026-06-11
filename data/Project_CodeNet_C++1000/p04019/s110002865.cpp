#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 505, mod = 924844033;
int n, a[maxn], ans[maxn*maxn];
vector<pair<int, int>> add[maxn*maxn];
multiset<pair<int, int>> x;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	#define ff(x) (count(all(s), x)>0)
	if(ff('N')^ff('S')) return cout << "No", 0;
	if(ff('E')^ff('W')) return cout << "No", 0;
	cout << "Yes";
}
