#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<utility>
#include<fstream>
#include<queue>
#include <iomanip>
#include<numeric>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define rep(i, k) for (i = 0; i < k; i++) 
typedef long long ll;
typedef pair<ll, ll> l_l;
int i, j;

ll b, k, n = 0, z = 0, x, y, a[200005] = {};
	vector<ll> v,vec;
	string s;
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	if (n % 2 == 0) {
		for (i = n - 1; i >= 0; i -= 2) {
			cout << a[i] <<" ";
		}
		for (i = 0; i < n; i += 2) {
			cout << a[i] << " ";
		}

	}
	if (n % 2 == 1) {
		for (i = n - 1; i >= 0; i -= 2) {
			cout << a[i] << " ";
		}
		for (i = 1; i < n; i += 2) {
			cout << a[i] << " ";
		}

	}
	

	return 0;

}
