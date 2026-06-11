#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void no(){cout << "No" << endl;}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    int m = n * n;
    vector<int> ans(m + 1, -1);
    vector<int> xv(n+1);
    vector<pair<int, pair<int,int> > > le;
    vector<pair<int, pair<int,int> > > ri;
    for(int i=1;i<=n;i++){
    	cin >> x;
    	xv[i] = x;
    	ans[x] = i;
    	if(x > 1 && i > 1) le.push_back({x, {i, i - 1}});
    	if(x < m && i < n) ri.push_back({x, {i, n - i}});
    }
    sort(be(le));
    sort(be(ri));
    deque<pair<int, int> > l, r;
    for(auto& i: le) l.pb(i.second);
    for(auto& i: ri) r.pb(i.second);
    for(int i=1;i<=m;i++){
    	if(l.empty()) break;
    	if(ans[i] == -1){
    		ans[i] = l.front().first;
    		if(l.front().second == 1) l.pop_front();
    		else l.front().second--;
    	}
    }
    for(int i=m;i>=1;i--){
    	if(r.empty()) break;
    	if(ans[i] == -1){
    		ans[i] = r.back().first;
    		if(r.back().second == 1) r.pop_back();
    		else r.back().second--;
    	}
    }
    vector<vector<int> > v(n+1, vector<int> ());
    for(int i=1;i<=m;i++){
    	if(ans[i] == -1){
    		no();
    	    return 0;
    	}
    	v[ans[i]].pb(i);
    }
    for(int i=1;i<=n;i++){
    	if(v[i].size() != n || v[i][i-1] != xv[i]){
    		no();
    		return 0;
    	}
    }
    cout << "Yes" << endl;
    for(int i=1;i<=m;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
