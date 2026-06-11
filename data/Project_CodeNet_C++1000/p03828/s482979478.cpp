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
#define rep(i,a,n) for(int i=(a);i<(n);i++)
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



int main() {
	int n;
	cin >> n;
	int s[1000] = { 0 };
	rep(i, 2, n+1) {
		int x = i;
		int j = 2;
		while (x > 1) {
			if (x % j == 0) {
				s[j]++;
				x /= j;
				j = 1;
			}
			j++;
		}
	}
	ll ans = 1;
	rep(i, 0, 1000) {
		ans *= (s[i] + 1);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}