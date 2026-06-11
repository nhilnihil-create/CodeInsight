#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

int main() {
	lint N;
	cin >> N;
	vector<lint>T(N);
	rep(i, N) {
		cin >> T[i];
	}
	lint M;
	cin >> M;
	vector<lint>P(M);
	vector<lint>X(M);
	rep(i, M) {
		cin >> P[i] >> X[i];
	}
	lint sum = 0;
	rep(i, N) {
		sum += T[i];
	}
	rep(i, M) {
		cout << sum - T[P[i] - 1] + X[i] << endl;
	}
}