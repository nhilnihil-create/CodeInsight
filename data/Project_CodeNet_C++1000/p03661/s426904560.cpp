#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#include<queue>
#include<functional>
#include<cassert>
#include<set>
#define rep(a,b) for(int a=0;a<b;++a)
#define REP(a,b,c,d) for(int a=b;a<c;a+=d)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
using p_i = pair<int, int>;
int main() {
	ll N, sum = 0; cin >> N;
	vector<ll> a(N);
	rep(i, N) {
		cin >> a[i];
		sum += a[i];
	}
	ll sumsum = 0, ans = 1e18;
	rep(i, N) {
		sumsum += a[i];
		if (i != N - 1)ans = min(ans, abs(sum - 2 * sumsum));
	}
	cout << ans << endl;
	cin >> N;
}