/*input
1
8 2 9
1 2
1 6
1 7
1 8
1 9
2 2
2 3
2 4
*/
#include<bits/stdc++.h>
using namespace std;

#define N 200009
#define oo 100000000000007
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define mp make_pair
#define iii pair< int, pair<int, ii> >
#define mod 1000000007
int n, m, l;
int pr1[N], pr2[N], usize[N];
map<ii, int> ma;
int find1(int i) { 
	return (pr1[i] == i) ? i : (pr1[i] = find1(pr1[i])); 
} 
int find2(int i){
	return (pr2[i] == i) ? i : (pr2[i] = find2(pr2[i]));
}

signed main()
{
	//freopen("ROADRAIL.INP", "r", stdin);
	//freopen("ROADRAIL.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> l;
	for(int i = 1; i <= n; ++i) pr1[i] = pr2[i] = i, usize[i] = 1;
	for(int i = 1; i <= m; ++i){
		int x, y; cin >> x >> y;
		if(find1(x) != find1(y)) 
			pr1[find1(x)] = find1(y);
	}
	for(int i = 1; i <= l; ++i){
		int x, y; cin >> x >> y;
		if(find2(x) != find2(y))
			pr2[find2(x)] = find2(y);
	}
	for(int i = 1; i <= n; ++i){
		int x = find1(i), y = find2(i);
		if(ma.find(ii(x, y)) == ma.end()) ma[ii(x, y)] = 1;
		else ma[ii(x, y)] ++ ;
	}
	for(int i = 1; i <= n; ++i){
		int x = find1(i), y = find2(i);
		cout << ma[ii(x, y)] << ' ';
	}
}	