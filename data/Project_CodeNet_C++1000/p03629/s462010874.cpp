#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<int,int>P;
#define INF (1<<29)
 
struct edge{
	int dst;
	ll cost;
	edge(int dst, ll cost){
		this->dst=dst; this->cost=cost;
	}

};


 
int V,E;
typedef vector<edge> edges;
vector<edges> g;

int nex[200005][30];
vector<int> dp;;

int main(){
	string s;
	cin >> s;
	dp.resize(s.size() + 5);
	rep(i, 26) {
		nex[s.size()][i] = s.size();
	}
	FORR(i, s.size() - 1, 0) {
		int c = s[i] - 'a';
		rep(j, 26) {
			if (j == c) {
				nex[i][j] = i;
			}
			else {
				nex[i][j] = nex[i + 1][j];
			}
		}

	}
	dp[s.size()] = 1;
	FORR(i, s.size() - 1, 0) {
		int mi = INF;
		rep(j, 26) {
			if (mi > dp[nex[i][j] + 1] + 1) {
				dp[i] = dp[nex[i][j] + 1] + 1;
				mi = dp[nex[i][j] + 1] + 1;
			}
		}
	}
	string ans;
	rep(i, s.size()) {
		int mi = INF;
		rep(j, 26) {
			if (mi > dp[nex[i][j] + 1] + 1) {
				mi = dp[nex[i][j] + 1] + 1;
			}
		}
		rep(j, 26) {
			if (mi == dp[nex[i][j] + 1] + 1) {
				ans += (j + 'a');
				i = nex[i][j];
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
