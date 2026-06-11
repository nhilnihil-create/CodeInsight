#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mt make_tuple
#define INF 2000000000
#define INFL 1000000000000000000LL
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<double, double> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<P> vP;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<P> > vvP;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<P, vector<P>, greater<P> > pqlP;
typedef pair<int, pair<int, int> > Edge;
typedef vector<Edge> vE;
typedef priority_queue<Edge, vector<Edge>, greater<Edge> > pqlE;

string debug_show(P a) {
	return "(" + to_string(a.first) + "," + to_string(a.second) + ")";
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W, d;
	cin >> H >> W >> d;

	if (d % 2 != 0) {
		rep(i, H) {
			rep(j, W) {
				if ((i + j) % 2 == 0) {
					cout << 'R';
				}
				else {
					cout << 'B';
				}
			}
			cout << endl;
		}
	}
	else {
		char c[4] = { 'R','G','B','Y' };
		vi num = { 1,d - 1,1,d - 1 };
		int col = 0, scol = 0;
		int asc = 1;

		rep(i, H) {
			int cnt = (num[0] + 1) / 2;
			rep(j, W) {
				cout << c[col];
				cnt--;
				if (cnt == 0) {
					col = (col + 1) % 4;
					cnt = num[col];
				}
			}
			cout << endl;
			if (i % (d / 2) == (d / 2) - 1){
				asc = 0;
			}
			else if ((i%d) / (d / 2) == 0) {
				asc = 1;
			}
			else {
				asc = -1;
			}
			if (asc == 1) {
				num[0]+=2;
				num[1]-=2;
				num[2]+= 2;
				num[3]-= 2;
			}
			else if(asc == -1){
				num[0]-= 2;
				num[1]+= 2;
				num[2]-= 2;
				num[3]+= 2;
			}

			if ((i + 1) % d == 0) {
				swap(c[0], c[2]);
			}
			else if (i % d == d / 2 - 1) {
				swap(c[1], c[3]);
			}
			col = scol;
		}
	}

	return 0;
}