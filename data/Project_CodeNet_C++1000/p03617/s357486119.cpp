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

int main() {
	long long int q, h, s, k;
	long long int  n;
	cin >> q >>  h >> s >> k >> n;
	vector<pair<long long int,long double>> a(4);
	a.at(0) = make_pair(8*q, 0.25);
	a.at(1)= make_pair(4*h, 0.50);
	a.at(2)= make_pair(2*s, 1.00);
	a.at(3)= make_pair(1*k,2.00);
	sort(a.begin(), a.end());
	//long double cnt = 0;
	long long int ans = 0;
	long double cnt = 0;
	if (n % 2 == 0) {
		ans += (long long int)((a.at(0).first/(2/a.at(0).second)) * (long long int)(n *(1/a.at(0).second)));

	}
	
	else {
		ans += (long long int)((a.at(0).first/(2/a.at(0).second)) * (long long int)((n - 1)* (1 / a.at(0).second)));
		while (cnt < 1) {
			if (cnt + a.at(0).second <= 1) {
				ans += (long long int)(a.at(0).first / (2 / a.at(0).second));
				cnt += a.at(0).second;
			}
			else if (cnt + a.at(1).second <= 1) {
				ans += (long long int)(a.at(1).first / (2 / a.at(1).second));
				cnt += a.at(1).second;
			}
			else if (cnt + a.at(2).second <= 1) {
				ans += (long long int) (a.at(2).first / (2 / a.at(2).second));
				cnt += a.at(2).second;
			}
			else if (cnt + a.at(3).second <= 1) {
				ans += (long long int) (a.at(3).first / (2 / a.at(3).second));
				cnt += a.at(3).second;
			}
		//	cout << cnt << endl;
		}
	}
	//cout << (long int)(100000000 * (1 / 0.25)) << endl;
	cout <<(long long int) ans << endl;
		return 0;
	}
