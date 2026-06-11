
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
#define MAX(a, b) ((ll)(a) > (ll)(b)) ? (ll)(a) : (ll)(b)
#define MIN(a, b) ((ll)(a) > (ll)(b)) ? (ll)(b) : (ll)(a)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 1000000007;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

ll min(ll a, ll b){
	if (a < b)
		return a;


		return b;
}


ll N, K;
vector<ll> A, B;



vector<ll> a;
ll b[30];



ll is_zero(ll a, ll k) {

	return ((a & (ll)pow(2, k)) == 0);
}

bool check(ll a, ll k) {


	



	if (k != -1) {
		for (int i = k; i < 30; i++) {

			if ((b[i] == 0 || i == k) && !is_zero(a, i))
				return false;

			
		}

	}

	else {
		for (int i = 0; i < 30; i++) {
			if (b[i] == 0 && !is_zero(a, i))
				return false;
		}
	}

	return true;
}


int main() {
	
	cin >> N >> K;

	ll u, v;

	rep(i, N) {
		cin >> v >> u;

		A.push_back(v);
		B.push_back(u);

	}

	rep(i, 30) {
		if ((K & (ll)pow(2.0, i)) != 0) {
			a.push_back(i);
			b[i] = 1;
		}
		

	}
	ll ans = 0;
	ll finalans = 0;
	reverse(a.begin(), a.end());


	rep(i, a.size()+1) {
		rep(j, N) {

			if (i != a.size()) {
				if (check(A[j], a[i]) == true) {

					ans += B[j];

				}

			}


			else {
				if (check(A[j], -1) == true)
					ans += B[j];

			}



		}


		finalans = MAX(ans, finalans);
		ans = 0;
	}


	
	cout << finalans << endl;
	

	return 0;
}