#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#define repp(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define repm(i,a,b) for(int i=(int)a;i>(int)b;--i)
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(3 * n);
	priority_queue<int>pq2;
	priority_queue<int, vector<int>, greater<int>>pq1;
	repp(i, 0, 3 * n) cin >> a[i];
	ll maxv=-INF;
	vector<ll>sum1(2*n, 0), sum2(3*n, 0);
	sum1[0] = a[0]; sum2[0] = a[3 * n - 1];
	repp(i, 1, n){
		sum1[i] =sum1[i-1]+a[i]; sum2[i]=sum2[i-1]+ a[3* n - i-1];
	}
	for (int i = 0; i < n; ++i)pq1.push(a[i]);
	for (int i = 2*n; i < 3 * n; ++i)pq2.push(a[i]);
	for (int i = n; i < 2*n; ++i) {
		pq1.push(a[i]);
		sum1[i] += sum1[i-1]+a[i];
		sum1[i] -= pq1.top(); pq1.pop();
	}
	for (int i = n; i < 2 * n;++i) {
		pq2.push(a[3*n-i-1]);
		sum2[i] += sum2[i-1] + a[3*n-i-1];
		sum2[i] -= pq2.top(); pq2.pop();
	}
	repp(i, n-1, 2 * n)maxv = max(maxv, sum1[i] - sum2[3*n-i-2]);
	cout << maxv << endl;
	return 0;
}