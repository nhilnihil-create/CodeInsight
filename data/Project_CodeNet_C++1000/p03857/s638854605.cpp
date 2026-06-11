#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pbb pair<bool,bool>
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define xmod (ll)(1e9+7) 
#define hmod 1286031825167LL
using namespace std;

int n,k,l,dsu_road[200005],dsu_rail[200005],u,v;
map <pii,int> m;
int find_road(int x){
	if (dsu_road[x] == x)
	return x;
	return dsu_road[x]=find_road(dsu_road[x]);
}
int find_rail(int x){
	if (dsu_rail[x] == x)
	return x;
	return dsu_rail[x]=find_rail(dsu_rail[x]);
}
int main(){	
    ios::sync_with_stdio(false);
    cin >> n >> k >> l;
    for (int i=1;i<=n;i++){
    	dsu_road[i]=i;
    	dsu_rail[i]=i;
	}
	for (int i=1;i<=k;i++){
		cin >> u >> v;
		dsu_road[find_road(u)]=find_road(v);
	}
	for (int i=1;i<=l;i++){
		cin >> u >> v;
		dsu_rail[find_rail(u)]=find_rail(v);
	}
	for (int i=1;i<=n;i++){
		m[mp(find_road(i),find_rail(i))]++;
	}
	for (int i=1;i<=n;i++){
		cout << m[mp(find_road(i),find_rail(i))] << " ";
	}
	cout << "\n";
    return 0;
}	