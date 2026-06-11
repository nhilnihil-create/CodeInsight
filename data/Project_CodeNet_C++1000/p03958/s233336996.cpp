#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(ll i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 100000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
struct edge { int to, cost; };

int seen[200001] = { false };
int a[200001] = { 0 };
int ans[200001] = { 0 };
void dfs(int v, int sum,whei(int)&G) {
	seen[v] = true;
	ans[v] = sum;
	for (auto x : G[v]) {
		if (seen[x])continue;
		dfs(x, sum + a[x], G);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	hei(Pint) a(k);
	priority_queue<Pint, hei(Pint)> Q;
	rep(i, 0, k) {
		cin >> a[i].first;
		a[i].second = i;
		Q.push(a[i]);
	}
	int ans = 0;
	if (k == 1)ans = n - 1;
	else {
		int x = -1;
		rep(i, 0, n) {
			Pint s = Q.top();
			Q.pop();
			if (s.second != x) {
				s.first--;
				x = s.second;
				Q.push(s);
			}
			else {
				Pint z = Q.top();
				Q.pop();

				if (z.first == 0) {
					ans++;
					s.first--;
					Q.push(s);
					Q.push(z);
				}
				else {
					z.first--;
					Q.push(z);
					Q.push(s);
					x = z.second;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}