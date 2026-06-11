#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;


int main() {
	int N;
	cin >> N;
	int count4 = 0;
	int count2 = 0;
	rep(i, N) {
		int x;
		cin >> x;
		if (x % 4 == 0)count4++;
		else if (x % 4 != 0 && x % 2 == 0)count2++;
	}
	int n = 2 * count4 + count2;
	if (n >= N||count4>=N/2) cout << "Yes" << endl;
	else cout << "No" << endl;
}