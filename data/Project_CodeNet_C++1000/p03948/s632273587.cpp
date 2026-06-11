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
using namespace std;
typedef  long long int lint;
typedef pair<int, int> P;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
const lint MOD = pow(10, 9) + 7;

int main() {
	int N, T;
	cin >> N >> T;
	vector<int>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	vector<int>V(N);
	V[0] = A[0];
	for (int i = 1; i < N; i++) {
		V[i] = min(A[i], V[i - 1]);
	}
	int d = 0;
	rep(i, N) {
		d = max(d, A[i] - V[i]);
	}
	int cnt = 0;
	rep(i, N) {
		if (A[i] - V[i] == d) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
