#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> PII;
typedef long long ll;
const int MAXN = 302;
ll dis[MAXN][MAXN];
vector<vector<PII> > edges;
vector<pair<int,PII>  >   d;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dis[i][j] = LLONG_MAX;
		}
	}
	
	edges.resize(n);
	for(int i=0;i<n;i++)
		edges[i] =vector<PII>();
	int a;

	for(int i=0;i<n;i++){
		for(int j= 0;j<n;j++){
			scanf("%d",&a);
			if (j> i){
				edges[i].pb(mp(j,a));
				edges[j].pb(mp(i,a));
				d.pb(mp(a,mp(i,j)));
			}
		}
	}
	//cout<<__LINE__<<endl;
	for (int i =0;i<n;i++){
		dis[i][i]  =0;
	}
	ll result = 0;
	for(int i=0;i<n;i++){
		for(PII p: edges[i]){
			dis[i][p.fi]  = p.se;
			result+=p.se;
		}
	}
	result = result/2;
	for(int k =0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j =0;j<n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	sort(d.begin(),d.end());
	//cout<<__LINE__<<endl;
	for(int i=d.size();i>= 0;i--){
		pair<int,PII> p  = d[i];
		int new_w = p.fi;
		int x = p.se.fi, y = p.se.se;
		bool other = false;
		for(int j=0;j<n;j++){
			if ( j==x || j==y)
				continue;
			if (dis[x][j]+dis[j][y] < new_w){
				printf("-1\n");
				return 0;
			}
			if (dis[x][j]+dis[j][y] == new_w){
				other = true;
			}
		}
		if (other){
			result -= new_w;
		}
	}
	printf("%lld",result);
	return 0;
}