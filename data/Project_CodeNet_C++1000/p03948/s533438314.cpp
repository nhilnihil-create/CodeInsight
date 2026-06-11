#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
const int INFTY = (1 << 21); // 2097152
// const ll INFTY = (1LL << 60);
const ll MD = 1000000007LL;
// fprintf(stderr, "%d %lld \n", x, xll);


int N, T;
int A[100000];

int main() {
	cin >> N >> T;
	rep(i, N) cin >> A[i];

	int mn;
	map<int, int> M;
	rep(i, N){
		if(i == 0){
			mn = A[i];
		}
		else{
			int y = A[i] - mn;
			if(y > 0){
				if(M.find(y) == M.end()) M[y] = 0;
				M[y]++;
			}
			mn = min(mn, A[i]);
		}
	}

	int mx = 0;
	for(auto &it: M){
		if(mx == 0) mx = it.first;
		else mx = max(mx, it.first);
	}
	cout << M[mx] << endl;
}