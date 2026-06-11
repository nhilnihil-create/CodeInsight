#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {

	int n;	
	cin >> n;

	vector<int> a(3 * n);
	for (int i = 0;i < 3 * n;i++) {
		cin >> a[i];
	}
	
	priority_queue<int,vector<int>,greater<int>> pq1;
	priority_queue<int> pq2;

	vector<ll> sum1(n + 1);
	vector<ll> sum2(n + 1);

	for (int i = 0; i < n;i++) {
		pq1.push(a[i]);
		sum1[0] += a[i];
		pq2.push(a[i + 2 * n]);
		sum2[n] += a[i + 2 * n];
	}

	//cout << sum1[0] << " " << sum2[n] << endl;
	

	for (int i = n; i < 2 * n;i++) {

		pq1.push(a[i]);
		sum1[i - (n - 1)] = sum1[i - n] - pq1.top();
		pq1.pop();
		sum1[i - (n - 1)] += a[i];
		//cout << sum1[i - (n - 1)] << " " << sum1[i - n] << endl;

	}

	for (int i = 2 *n-1; i>=  n;i--) {

		pq2.push(a[i]);
		sum2[i - n] = sum2[i - n + 1] - pq2.top();
		pq2.pop();
		sum2[i - n] += a[i];

	}



	ll ans = -BIG_NUM;
	for (int i = 0; i <= n;i++) {
		ans = max(ans, sum1[i] - sum2[i]);
		//cout <<i << " " << sum1[i] << " " << sum2[i] << endl;
	}
	cout << ans << endl;
	
}
