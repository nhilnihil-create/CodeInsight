#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr = ds.begin(); itr != ds.end(); ++itr)
#define mp make_pair
#define INF 2000000000
#define INFL 2000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<P> vP;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<double> > vvd;
typedef vector<vector<P> > vvP;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<P, vector<P>, greater<P> > pqlP;
typedef pair<int, pair<int, int> > Edge;

int main() {
	ll N;
	cin >> N;
	N++;
	deque<int> a, b;
	int left = 1;
	while ((N >> left) > 0)left++;
	int num = 1;
	reprev(i, left - 1) {
		a.push_back(num);
		b.push_back(num);
		num++;
		if ((N >> i) % 2 == 1) {
			a.push_back(num);
			b.push_front(num);
			num++;
		}
	}
	cout << a.size() + b.size() << endl;
	while(!a.empty()) {
		cout << a.front() << ' ';
		a.pop_front();
	}
	while(!b.empty()) {
		cout << b.front();
		b.pop_front();
		if (!b.empty())cout << ' ';
	}
	cout << endl;
	return 0;
}