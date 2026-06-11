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
const ll MOD = (1e+9)+7;
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
typedef pair<ll,P> PP;
int h, w,d;
char m[1000][1000];
void out() {
	rep(i, h) {
		rep(j, w) {
			cout << m[i][j];
		}
		cout << endl;
	}
}
char t[4] = { 'R','Y','B','G' };
char k[4][500][500];
char inv(char aaa) {
	if (aaa == 'R')return 'B';
	else if (aaa == 'B')return 'R';
	else if (aaa == 'Y')return 'G';
	else return 'Y';
}
int main() {
	cin >> h >> w >> d;
	if (d % 2) {
		rep(i, h) {
			rep(j, w) {
				if ((i + j) % 2) {
					m[i][j] = 'R';
				}
				else m[i][j] = 'G';
			}
		}
	}
	else {
		int dd = d / 2;
		int cnt = 0;
		rep(i, dd) {
			rep(j, dd) {
				if (i <= j) {
					k[0][i][j] = 'R';
					k[3][i][j] = 'G';
				}
				else {
					k[0][i][j] = 'Y';
					k[3][i][j] = 'B';
				}
				if (dd-i-1 >= j) {
					k[1][i][j] = 'R';
					k[2][i][j] = 'Y';
				}
				else {
					k[1][i][j] = 'G';
					k[2][i][j] = 'B';
				}
			}
		}
		for (int i = 0; i < h; i += d) {
			for (int j = 0; j < w; j += d) {
				if ((i/d + j/d) % 2) {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = inv(k[0][x][y]);
						}
					}
				}
				else {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = k[0][x][y];
						}
					}
				}
			}
		}
		for (int i = 0; i < h; i += d) {
			for (int j = dd; j < w; j += d) {
				if ((i / d + j / d) % 2) {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = inv(k[1][x][y]);
						}
					}
				}
				else {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = k[1][x][y];
						}
					}
				}
			}
		}
		for (int i = dd; i < h; i += d) {
			for (int j = 0; j < w; j += d) {
				if ((i / d + j / d) % 2) {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = inv(k[2][x][y]);
						}
					}
				}
				else {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = k[2][x][y];
						}
					}
				}
			}
		}
		for (int i = dd; i < h; i += d) {
			for (int j = dd; j < w; j += d) {
				if ((i / d + j / d) % 2) {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = inv(k[3][x][y]);
						}
					}
				}
				else {
					rep(x, dd) {
						rep(y, dd) {
							int nx = i + x; int ny = j + y;
							m[nx][ny] = k[3][x][y];
						}
					}
				}
			}
		}
	}
	out();
	return 0;
}