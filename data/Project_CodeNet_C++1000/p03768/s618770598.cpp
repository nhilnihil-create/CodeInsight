#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct node{
	int now, dis, col;
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<int> > v(n);
    for(int i=0;i<m;i++){
    	cin >> a >> b;
    	a--;b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    vector<int> used(n, -1), ans(n, 0);
    int q;
    cin >> q;
    vector<node> query(q);
    for(int i=0;i<q;i++){
    	cin >> a >> b >> c;
    	query[i] = {a - 1, b, c};
    }
    while(q--){
    	c = query[q].col;
    	queue<pair<int,int> > que;
    	que.push({query[q].now, query[q].dis});
    	while(!que.empty()){
    		int e = que.front().first;
    		int d = que.front().second;
    		que.pop();
    		if(d <= used[e]) continue;
    		used[e] = d;
    		if(ans[e] == 0) ans[e] = c;
    		for(auto& to: v[e]){
    			que.push({to, d - 1});
    		}
    	}
    }
    for(auto& i: ans) cout << i << endl;
    return 0;
}
