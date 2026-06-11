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
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
int dp[5005][5005];
string s;
int main(){
	cin >> n >> s;
	dp[0][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
			dp[i+1][max(0,j-1)] = (dp[i+1][max(0,j-1)]+dp[i][j]*(j?2:1)%mod)%mod;
		}
	}
	int hoge = dp[n][s.size()];
	cout << hoge << endl;
}