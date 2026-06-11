#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct node{ll x, y, cost;};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll dis[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    	if(i == j) dis[i][j] = 0;
    	else dis[i][j] = INF;
    }
    vector<node> v;
    ll a, b, c;
    for(int i=0;i<m;i++){
    	cin >> a >> b >> c;
    	a--;b--;
        v.push_back({a, b, c});
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }
    for(int k=0;k<n;k++){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
    		}
    	}
    }
    ll ans = 0;
    for(int k=0;k<m;k++){
    	a = v[k].x;
    	b = v[k].y;
    	c = v[k].cost;
    	bool maki = false;
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		if(dis[i][j] == dis[i][a] + dis[b][j] + c) maki = true;
        	}
        }
        if(maki) ans++;
    }
    cout << m - ans << endl;
    return 0;
}
