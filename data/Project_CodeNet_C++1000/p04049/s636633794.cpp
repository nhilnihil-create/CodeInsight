#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const double PI  = 3.1415926535897932384626433832795028841971;
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n, k;
vector<int> e[4000];
int dist[4000][4000];
bool saw[4000][4000];
template<typename Type>
void showContent1D(Type input)
{
	for(int i=0; i<=10; ++i)
	{
		cout<<input[i]<<", ";
	}
	return;
}
template<typename Type>
void showContent2D(Type input)
{
	for(int i=0; i<=7; ++i)
	{
		for(int j=0; j<=10; ++j)
		{
			cout<<input[i][j]<<", ";
		}
		cout<<endl;
	}
	return;
}
void dfs(int ro, int v, int d, int par){
	//rep(i,e[v].size())
  	for(int i=0; i<e[v].size(); ++i)
    {
		if(e[v][i] == par) continue;
		dist[ro][e[v][i]] = d+1;
		dfs(ro,e[v][i],d+1,v);
	}
}
int main(){
	cin >> n >> k;
	rep(i,n-1){
		int a, b;
		cin >> a >> b;
		//a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	//#define rep(i,n) for(int i = 0; i < n; i++)
	//rep(i,n) dfs(i,i,0,-1);
	for(int i=1; i<=n; ++i)
	{
		dfs(i, i, 0, -1);
	}
	int ans = 0;
	bool ok = false;
	//rep(i,n) for(int j = i+1; j < n; j++){
	for(int i=1; i<=n; ++i)
	{
		for(int j = i+1; j <= n; j++)
		{
			if(dist[i][j] != k || saw[i][j] == true) continue;
			ok = true;
			int cnt = 0;
			//rep(l,n)
			for(int l=1; l<=n; ++l)
			{
				if(dist[l][i] <= k && dist[l][j] <= k)
				{
					cnt++;
					saw[l][i] = true; saw[l][j] = true;
					saw[i][l] = true; saw[j][l] = true;
				}
			}
			ans = max(ans,cnt);
		}
	}
	if(!ok) cout << 0 << endl;
	else cout << n-ans << endl;
}
