#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

int a,b,c,d,e,f;
pair<int,int> dp[3001][3001];
bool vis[3001][3001];
pair<int,int> func(int w, int s) {
    if (w > f) return { 1,-1000 };
	if (vis[w][s]) return dp[w][s];
	vis[w][s] = 1;
 
	pair<int,int> temp{w,s};
	dp[w][s] = temp;
	double score = (double)(s) / w;
	if (w == 0) score = -1;
	temp = func(w + 100 * a, s);
	if (score < (double)(temp.second) / temp.first) {
		score = (double)(temp.second) / temp.first;
		dp[w][s] = temp;
	}
	temp = func(w + 100 * b, s);
	if (score < (double)(temp.second) / temp.first) {
		score = (double)(temp.second) / temp.first;
		dp[w][s] = temp;
	}
	if (s + c <= (w - s)*e/100)	{
		temp = func(w + c, s + c);
		if (score < (double)(temp.second) / temp.first) {
			score = (double)(temp.second) / temp.first;
			dp[w][s] = temp;
		}
	}
	if (s + d <= (w - s)*e / 100) {
		temp = func(w + d, s + d);
		if (score < (double)(temp.second) / temp.first) {
			score = (double)(temp.second) / temp.first;
			dp[w][s] = temp;
		}
	}
	return dp[w][s];
}

void solve() {
    cin>>a>>b>>c>>d>>e>>f;
    pair<int,int> res = func(0,0);
    cout<<res.first<<" "<<res.second<<endl;
}

int main() {
    solve();
    return 0;
}