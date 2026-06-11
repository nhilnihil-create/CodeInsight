#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#define popcount __builtin_popcount
using namespace std;

/***/
//#include <iomanip>
//#include <cmath>
//#include <bits/stdc++.h>

#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define rrep(i,x) for(long long i=x-1;i>=0;i--)
#define rrepn(i,x) for(long long i=x;i>1;i--)

#define pr printf
#define re return
#define mod 1000000007
#define fi first
#define se second
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
/***/

typedef long long int ll;
typedef pair<int, int> P;
int n;
//vector<int> g[200020];
vector<pair<int,int>> g[200020];
ll s[200020];
bool used[200020];
int ans;

int main()
{
	ll wk;
	wk=0;
    cin.tie(0);
    ios::sync_with_stdio(false);
    
	string s;
	cin >> s;

	//bool dp[100005];
	
	bool dp[s.size()+1];
	rep(i,s.size()+1){
		dp[i]=0;
	}
	s.insert(0, " ");
	s[0]=' ';
	dp[0]=1;
	repn(i,s.size()){
		if(5<=i && s.substr(i-4,5)=="dream" && dp[i-5]==1){
			dp[i]=1;
		}
		if(7<=i && s.substr(i-6,7)=="dreamer" && dp[i-7]==1){
			dp[i]=1;
		}
		if(5<=i && s.substr(i-4,5)=="erase" && dp[i-5]==1){
			dp[i]=1;
		}
		if(6<=i && s.substr(i-5,6)=="eraser" && dp[i-6]==1){
			dp[i]=1;
		}
	}
	if(dp[s.size()-1]==1){
		puts("YES");
	}
	else{
		puts("NO");
	}
	re 0;
	return 0;
}
