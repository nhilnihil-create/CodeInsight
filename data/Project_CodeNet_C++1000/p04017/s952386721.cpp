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
#define mp make_pair

using namespace std;

const int MAXN = 100000+5;
const int LOGN = 18;
const int INF = 1e9;

int _next[LOGN][MAXN];

void solve(){
	int n;
	cin >> n;
	int arr[n];
	FOR(i,n)cin >> arr[i];
	int L;cin >> L;
	int lst = n-1;
	for(int i = n-1;i>=0;i--){
		if(i == n-1)_next[0][i] = INF;
		else{
			while(arr[lst] - arr[i] > L)lst--;
			_next[0][i] = lst;
		}
	}
	FOR(i,LOGN){
		if(i == 0)continue;
		FOR(j,n){
			int it = _next[i-1][j];
			if(it == INF)_next[i][j] = INF;
			else _next[i][j] = _next[i-1][it];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;a--;b--;
		if(a > b)swap(a,b);
		if(a == b){
			cout << 0 << endl;
			continue;
		}
		int sum =  0;
		for(int i = LOGN-1;i>=0;i--){
			if(_next[i][a] < b)a = _next[i][a],sum += (1 << i);
		}
		sum ++ ;
		cout << sum << endl;
	}
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