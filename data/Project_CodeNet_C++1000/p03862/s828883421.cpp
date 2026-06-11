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
	lint N, X;
	cin >> N >> X;
	vector<lint>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	lint ans = 0;
	rep(i, N-1) {
		if (i == 0) {
			if (A[i] >= X) {
				ans += A[i+1];
				A[i+1] = 0;
				ans += A[i] - X;
				A[i] = X;
			}
			else {
				ans += max(lint(0),A[i] + A[i + 1] - X);
				A[i + 1] -= max(lint(0),(A[i] + A[i + 1]) - X);
			}
		}
		else if (i == N - 2) {
			if (A[i+1] >= X) {
				ans += A[i];
				A[i] = 0;
				ans += A[i+1] - X;
				A[i+1] = X;
			}
			else {
				ans += max(lint(0),A[i] + A[i + 1] - X);
				A[i] -= max(lint(0),(A[i] + A[i + 1]) - X);
			}
		}
		else {
			if (A[i] >= X) {
				ans += A[i + 1];
				A[i + 1] = 0;
				ans += A[i] - X;
				A[i] = X;
			}
			else {
				ans += max(lint(0),A[i] + A[i + 1] - X);
				A[i + 1] -= max(lint(0),(A[i] + A[i + 1]) - X);
			}
		}
	}
	cout << ans << endl;
}