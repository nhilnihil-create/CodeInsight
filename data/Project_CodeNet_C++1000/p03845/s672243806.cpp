#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main(){
	int n;
	cin >> n;
	vector<int> t(n+1);
	for (int i = 0; i < n; i++) {
		cin >> t.at(i);
	}
	int m;
	cin >> m;
	vector<int> p(m+1), x(m+1);
	
	for (int i = 0; i < m; i++) {
		cin >> p.at(i) >> x.at(i);
	}

	int ans = INF;
	int d = 0;
	for (int i = 0; i < n; i++) {
		d += t.at(i);
	}
	int total = d;
	//cout << total << endl;
	for (int i = 0; i < m; i++) {
		
		total -= t.at(p.at(i)-1);
		total += x.at(i);
		cout << total << endl;
		total = d;
	}
	
	
	
	return 0;
}