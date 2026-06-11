#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
vector<vector<int> > v(100000);
int dfs(int now,int p){
	int ret = 0;
	for(auto& to:v[now]){
		if(to == p) continue;
		ret ^= (dfs(to,now)+1);
	}
	return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n;
    for(int i=1;i<n;i++){
    	cin >> a >> b;
    	a--;b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    if(dfs(0,-1))cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}
