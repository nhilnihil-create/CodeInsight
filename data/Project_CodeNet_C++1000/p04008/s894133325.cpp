#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

vector<vector<int> > v;
int ans = 0, k;
int dfs(int now){
	if(v[now].empty()) return 0;
	int ret = 0;
	for(auto to: v[now]){
		int num = dfs(to);
		if(now && num >= k - 1) ans++, num = -1;
		ret = max(ret, num + 1);
	}
	return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, a;
    cin >> n >> k;
    v.resize(n);
    for(int i=0;i<n;i++){
    	cin >> a;
    	a--;
    	if(i) v[a].pb(i);
    	else if(a) ans++;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
