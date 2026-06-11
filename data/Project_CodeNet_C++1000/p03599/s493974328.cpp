#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;

int main() {
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;

	double mxc = 0;
	int answ = 100*a, ansc = 0;

	rep(i, 31)rep(j, 31)rep(k, 3001) {
		if (i == 0 && j == 0)continue;
		if (f < (100 * a * i + 100 * b * j + c * k))continue;
		if (e * (a * i + b * j) < c * k)continue;
		int l1 = (f - (100 * a * i + 100 * b * j + c * k))/d;
		int l2 = (e * (a * i + b * j) - c * k) / d;
		int l = min(l1, l2);
		

		int water = 100 * a * i + 100 * b * j;
		int nacl = c * k + d * l;

		double cc = nacl / ((double)water + nacl);
		if (mxc < cc) {
			answ = water + nacl;
			ansc = nacl;
			mxc = cc;
		}
	}
	cout << answ << " " << ansc << endl;
}