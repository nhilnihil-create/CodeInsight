#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[505];
vector<int>ans; vector<P>vec; queue<int>Q;
vector<int>x[505];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		 cin >> a[i];
		vec.pb(mp(a[i],i));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		for(int x=1;x<vec[i].sc;x++){
			Q.push(vec[i].sc);
		}
	}
	int nxt = 0;
	for(int i=0;i<n*n;i++){
		if(nxt < n && i+1 == vec[nxt].fi){
			ans.pb(vec[nxt].sc);
			for(int j=0;j<n-vec[nxt].sc;j++){
				Q.push(vec[nxt].sc);
			}
			nxt++;
		}
		else{
			if(Q.empty()){
				puts("No"); return 0;
			}
			ans.pb(Q.front()); Q.pop();
		}
	}
	for(int i=0;i<n*n;i++){
		x[ans[i]].pb(i+1);
	}
	for(int i=1;i<=n;i++){
		if(a[i] != x[i][i-1]){
			puts("No"); return 0;
		}
	}
	puts("Yes");
	for(int i=0;i<n*n;i++) printf("%d%c",ans[i],(i==n*n-1?'\n':' '));
}