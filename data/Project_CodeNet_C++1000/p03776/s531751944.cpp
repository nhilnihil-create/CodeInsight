
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
	int n, a, b; 
	cin >> n >> a >> b;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(),greater<ll>());

	ll sum = 0;
	for (int i = 0;i < a;i++) {
		sum += v[i];
	}

	double ave = sum / (1.0*a);

	cout << setprecision(22) << ave << endl;

	int cnt = 0;
	for (int i = a;i < n;i++) {
		if (v[i] == v[i - 1]) {
			cnt++;
		}
		else {
			break;
		}
	}


	/*
	vector<ll> facto(n+1);
	facto[0] = 1;
	for (int i = 1; i <= n;i++) {
		facto[i] = facto[i - 1] * i;
		cout << facto[i] << endl;
	}
	*/


	if (v[0] == v[a - 1]) {
		
		ll ans = 0;
		cnt += a;
		//cout << cnt << endl;
		for (int i = a; i <= min(b,cnt);i++) {
			map<ll,int> m;
			for (int j = 0; j < i;j++) {
				int num = cnt-j;
				//cout << num << " " << i << endl;
				for (int k = 2; k*k <= num;k++) {
					while (num %k == 0) {
						m[k]++;
						num /= k;
					}

					
				}
				if (num != 1) {
					m[num]++;
				}
				if (j > 0) {
					num = j + 1;
					for (int k = 2; k*k <= num;k++) {
						while (num %k == 0) {
							m[k]--;
							num /= k;
						}


					}
					if (num != 1) {
						m[num]--;
					}
				}
			}
			ll tmp = 1;

			for (auto it = m.begin();it != m.end();it++) {
				for (int j = 0; j < it->second;j++) {
					tmp *= it->first;
					
				}

				

				
				//cout << it->first << " " << it->second << endl;
			}
			//cout << endl;
			ans += tmp;
			//cout << tmp << endl;
		}

		cout << ans << endl;
	}
	else {

		ll ans = 1;
		int c = 0;
		
		for (int i = a;i > 0;i--) {
			if (v[i] == v[i - 1]) {
				c++;
			}
		}
		cnt += c;
		map<ll, int> m;
		for (int j = 0; j < c;j++) {
			int num = cnt - j;
			//cout << num << " " << i << endl;
			for (int k = 2; k*k <= num;k++) {
				while (num %k == 0) {
					m[k]++;
					num /= k;
				}


			}
			if (num != 1) {
				m[num]++;
			}
			if (j > 0) {
				num = j + 1;
				for (int k = 2; k*k <= num;k++) {
					while (num %k == 0) {
						m[k]--;
						num /= k;
					}


				}
				if (num != 1) {
					m[num]--;
				}
			}
		}
		ll tmp = 1;

		for (auto it = m.begin();it != m.end();it++) {
			for (int j = 0; j < it->second;j++) {
				tmp *= it->first;

			}
		}
		ans = tmp;
		
		
		cout << ans << endl;
	}

}



