#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <random>
#include <functional>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VD vector<double>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define MAP map<int,int>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;
const ll INF = (ll)1e17;

void ANS(bool flag) {
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Ans(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void ans(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}

int main() {
	int N;ll T;
	cin >> N >> T;
	VL A(N),B(N),C(N,0);
	REP(i, N) cin >> A[i];
	C[N - 1] = A[N - 1];
	REREP(i, N - 1) C[i] = max(C[i + 1], A[i]);
	REP(i, N) B[i] = C[i] - A[i];
	//REP(i, N) cout << A[i] << " " << B[i] << " " << C[i] << endl;
	ll B_max = *max_element(B.begin(), B.end());
	ll cnt = 0;
	REP(i, N - 1) if (B_max == B[i]) cnt++;
	cout << cnt << endl;
	//cin >> N;
	return 0;
}
