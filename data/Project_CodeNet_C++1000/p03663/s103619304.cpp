#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 924844033;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int main() {
	char memo = 'a';
	int chk = -1;char s; 
	per(i, 10) {
		int t = (int)pow(10, i);
		cout << "? " << t << endl;
		cin >> s;
		if (memo == 'a') {
			memo = s;
		}
		else {
			if (memo != s) {
				chk = i; break;
			}
		}
	}
	if (chk == -1) {
		rep(i, 11) {
			cout << "? " << 2 * (ll)pow(10, i) << endl;
			cin >> s;
			if (s == 'Y') {
				cout << "! " << (ll)pow(10, i) << endl; break;
			}
		}
	}
	else {
		int now = 0;
		rep(i, chk) {
			now *= 10;
			cout << "? " <<now+5<< endl;
			cin >> s;
			if (s == 'Y') {
				cout << "? " << now + 7 << endl;
				cin >> s;
				if (s == 'Y') {
					cout << "? " << now + 8 << endl;
					cin >> s;
					if (s == 'Y') {
						cout << "? " << now + 9 << endl;
						cin >> s;
						if (s == 'Y') {
							now += 9;
						}
						else {
							now += 8;
						}
					}
					else {
						now += 7;
					}
				}
				else {
					cout << "? " << now + 6 << endl;
					cin >> s;
					if (s == 'Y') {
						now += 6;
					}
					else {
						now += 5;
					}
				}
			}
			else {
				cout << "? " << now + 3 << endl;
				cin >> s;
				if (s == 'Y') {
					cout << "? " << now + 4 << endl;
					cin >> s;
					if (s == 'Y') {
						now += 4;
					}
					else {
						now += 3;
					}
				}
				else {
					cout << "? " << now + 2 << endl;
					cin >> s;
					if (s == 'Y') {
						now += 2;
					}
					else {
						cout << "? " << now + 1 << endl;
						cin >> s;
						if (s == 'Y') {
							now += 1;
						}
					}
				}
			}
		}
		now *= 10;
		ll nex = (ll)10 * now;
		if (nex == 0) {
			Rep(j, 1, 10) {
				cout << "? " << nex + (ll)10 * j << endl;
				cin >> s;
				if (s == 'Y') {
					now += j; break;
				}
			}
		}
		else {
			rep(j, 10) {
				cout << "? " << nex + (ll)10 * j << endl;
				cin >> s;
				if (s == 'Y') {
					now += j; break;
				}
			}
		}
		cout << "! " << now << endl;
	}
	return 0;
}