#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=0;i--)
#define rep_re(i,s,n)for(int i = n;i>=0;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_M = 100001;

int main() {
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	for (ll i = 0; i < N; i++) {
		//i回は大きくなり,N - 1 - i回は小さくなる
		ll max = A + i * D - (N - 1 - i) * C;
		ll min = A + i * C - (N - 1 - i) * D;
		if (min <= B && B <= max) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}