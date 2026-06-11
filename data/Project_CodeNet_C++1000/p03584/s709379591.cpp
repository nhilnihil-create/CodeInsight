#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
	int n,k;
	cin >> n >> k;
	k = (k<<1)^1;
	vector<int> a(n),b(n);
	for (int i = 0;i < n;++i) cin >> a[i] >> b[i];
	vector<ll> ans(31,0);
	for (int i = 0;i < n;++i) {
		a[i] <<= 1;
		for (int j = 30;j >= 0;--j) {
			if ((k>>j)&1 && !((a[i]>>j)&1)) ans[j] += b[i];
			else if (!((k>>j)&1) && ((a[i]>>j)&1)) break;
		}
	}
	// p_ary(ans,0,31,i);
	cout << *max_element(ans.begin(),ans.end()) << endl;
	return 0;
}