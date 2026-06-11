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

ll K;
const ll N = 50;
ll a[50];

int main() {

	cin >> K;
	ll d = K / N;
	ll m = K % N;
	rep(i, N){
		a[i] = N - 1 + d;
	}

	rep(mm, m){
		rep(i, N){
			if(i == mm) a[i] += N;
			else a[i]--;
		}
	}

    cout << N << endl;
	rep(i, N){
		cout << a[i];
		if(i == N-1) cout << endl;
		else cout << " ";
	}
}