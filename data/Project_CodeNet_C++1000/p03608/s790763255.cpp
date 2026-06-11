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
#define rep(i,a,n) for(llint i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
const ll mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const ll INF = 1000000000;


int main() {
	int n, m, r;
	cin >> n >> m >> r;
	whei(llint) dist(200, hei(llint)(200, 10000000));
	rep(i, 0, 200)dist[i][i] = 0;
	int a[8];
	rep(i, 0, r) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, 0, m) {
		int A, B; 
		llint C;
		cin >> A >> B >> C;
		A--;
		B--;
		dist[A][B] = min(dist[A][B], C);
		dist[B][A] = min(dist[B][A], C);
	}
		rep(k, 0, n) {
			rep(i, 0, n) {
				rep(j,0,n){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			    }
		    }
	    }
	llint ans = INF;
	sort(a, a + r);
	do {
		llint sum = 0;
		rep(i, 0, r - 1)sum += dist[a[i]][a[i + 1]];
		ans = min(ans, sum);

	} while (next_permutation(a, a + r));
	cout << ans << endl;
	return 0;
}