#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<math.h>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vtype(type) vector<type>
#define vvtype(type) vector<vector<type>>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;

ll const MAX = 105;
vll a(MAX);

int main() {
	ll n, m;
	cin >> n >> m;
	REP(i, 1, m) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << endl << 1 << endl << 1 << endl;
		return 0;
	}
	ll odd = 0;
	vll odd_ad(MAX);
	REP(i, 1, m) {
		if (a[i] % 2 == 1) {
			odd++;
			odd_ad[odd] = i;
		}
	}
	if (n % 2 == 0) {
		if (odd == 0) {
			REP(i, 1, m) {
				cout << a[i];
				if (i < m) {
					cout << " ";
				}
			}
			cout << endl;
			if (a[1] == n) {
				cout << 2 << endl << n - 1 << " " << 1 << endl;
			}
			else {
				cout << m << endl << a[1] - 1 << " ";
				REP(i, 2, m - 1) {
					cout << a[i] << " ";
				}
				cout << a[m] + 1 << endl;
			}
		}
		else if (odd == 2) {

			swap(a[1], a[odd_ad[1]]);
			swap(a[m], a[odd_ad[2]]);
			REP(i, 1, m) {
				cout << a[i];
				if (i < m) {
					cout << " ";
				}
			}cout << endl;

			if (a[m] == 1) {
				cout << m - 1 << endl;
				cout << a[1] + 1 << " ";
				REP(i, 2, m - 1) {
					cout << a[i];
					if (i < m - 1) {
						cout << " ";
					}
				}
				cout << endl;
			}
			else {
				cout << m << endl;
				cout << a[1] + 1 << " ";
				REP(i, 2, m - 1) {
					cout << a[i] << " ";
				}
				cout << a[m] - 1 << endl;
			}
		}
		else {
			cout << "Impossible" << endl;
		}
	}
	else {
		if (m == 1) {
			cout << n << endl;
			cout << 2 << endl;
			cout << n - 1 << " " << 1 << endl;
		}
		else if (odd != 1) {
			cout << "Impossible" << endl;
		}
		else {
			swap(a[1], a[odd_ad[1]]);
			REP(i, 1, m) {
				cout << a[i];
				if (i < m) {
					cout << " ";
				}
			}
			cout << endl;
			cout << m << endl;
			cout << a[1] + 1 << " ";
			REP(i,2,m-1){
				cout << a[i] << " ";
			}
			cout << a[m] - 1 << endl;
		}
	}
}