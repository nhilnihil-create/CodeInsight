#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
//#define f first
//#define s second
//#define mp make_pair
#define gg return 0;
#define pii pair < int, int>
 
using namespace std;
 
const int maxn = 132675;
const int INF = (int)1e9;
 
ll a,b[maxn],c,d,cnt,e[(int)2e3 + 1][(int)2e3 + 1],cost[maxn],tout[maxn],mn = INF,mx = -INF,l,r;
 
ll x[maxn],y[maxn],x2[maxn],y2[maxn];
 
bool u[maxn], m, f;
 
vector <int> v;
 /*
void forn( int s, int f, int inter){
	for(int i = s; i <= f; i += inter){
		b[i] = i;
	}
}
*/ 
ll ans;
 
ll pref;
 
//vector <int> g[maxn],d[maxn];
 
ll lvlc,lvl[maxn];
/*
void dfs(int v){
	lvlc++;
	lvl[v] = lvlc;
	d[lvl[v]].pb(v);
	u[v] = 1;
	for(int i = 0; i < g[v].size(); ++i){
		int to = g[v][i];
		if(!u[to]){
			dfs(to);
		}
	}
	lvlc--;
}*/

map <int, int> mp; 
 
char ch;

string s; 

int main()
{
	int t;
	cin >> a >> t;
	for(int i = 1; i <= a; ++i){
		cin >> b[i];
	}
	for(int i = 1; i <= a; ++i){
		mn = min(mn,b[i]);
		mp[b[i] - mn]++;
	}
	cout << mp.rbegin() -> second;
	gg
}