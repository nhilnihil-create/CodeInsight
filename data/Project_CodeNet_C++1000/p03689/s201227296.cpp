#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////



int main() {
	
	ll H, W, h, w;
	cin >> H >> W >> h >> w;

	if (H%h == 0 && W%w == 0) { cout << "No"; }
	else {
		cout << "Yes" << endl;

		ll M = (H-1) / h+1;
		ll N = (W-1) / w+1;

		ll pos = M * N;
		ll neg = H * W - pos;

		ll T = pos / ((h*w - 1)*pos - neg) + 1;





		ll X = T * (h*w - 1) - 1;
		ll Y = -T;

		//cout << X << Y;

		
		rep(i, H){
			rep(j, W) {
				if (i%h == 0 && j%w == 0) { cout << X; }
				else { cout << Y; }
				cout << " ";
			}
			cout << endl;
		}
		
	}


	system("PAUSE");
}
