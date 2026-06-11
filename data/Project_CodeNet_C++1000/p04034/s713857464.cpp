#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
//#define int long long
#define ld long double
#define vi deque<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<int,ll>
#define pll pair<ll,ll>
#define _path pair<ll,pair<ll,int> > 
#define vv deque
//#define endl '\n'
//#define mp make_pair

using namespace std;

const int MAXN = 1e5+5;


void solve(){
	int n,m;
	cin >> n >> m;

	bool hasRedball[n];
	int tot[n];
	FOR(i,n)hasRedball[i] = 0;
	FOR(i,n)tot[i] = 1;
	hasRedball[0] = 1;
	FOR(i,m){
		int a,b;
		cin >> a >> b;
		a--;b--;
		if(hasRedball[a])hasRedball[b] = 1;
		tot[a]--;
		tot[b]++;
		if(tot[a] == 0)hasRedball[a] = 0;
	}
	int cnt =0 ;
	FOR(i,n)cnt += hasRedball[i];
	cout << cnt << endl;
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}