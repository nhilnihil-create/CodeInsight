#include <bits/stdc++.h>
#define int llint
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) ((((a)%MOD)+((b)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define CEIL(x) ((int)ceil(((double)x)))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define EPS (1e-20)
#define INF 214748364700000
#define MOD 1000000007
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using VLL = std::vector<llint>;
using MCI = std::map<char, int>;
using namespace std;


int N;
int a[300010];
int suml[300010], sumr[300010];


void makeSumL(){
	int s = 0;
	priority_queue<int, VI, greater<int>> q;
	rep(i, 0, N) q.push(a[i]), s += a[i];
	repe(i, N, 2*N){
		suml[i] = s;
		q.push(a[i]);
		s += a[i];
		s -= q.top();
		q.pop();
	}
}


void makeSumR(){
	int s = 0;
	priority_queue<int> q;
	repr(i, 3*N, 2*N) q.push(a[i]), s += a[i];
	reper(i, 2*N, N){
		sumr[i] = s;
		q.push(a[i-1]);
		s += a[i-1];
		s -= q.top();
		q.pop();
	}
}


int solve(){
	int ans = -INF;
	repe(i, N, 2*N) chmax(ans, suml[i]-sumr[i]);
	return ans;
}


signed main(){
	cin >> N;
	rep(i, 0, 3*N) cin >> a[i];

	makeSumL();
	makeSumR();

	cout << solve() << endl;

	return 0;
}