#include <iostream>
#include <algorithm>
#include<string>
#include<cmath>
#include<stack>
#include <vector>
#include<queue>
#include <random>
#include <cstdint>
#include <bitset>
#include <iomanip>
#include<utility>
using namespace std;
using ll = long long;
const ll modulo = 1000000007;

int main(){
	int n, m;
	ll x[100000], y[100000];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}
	ll sumx = 0, sumy = 0;
	for (int i = 0; i < n; i++) {
		sumx += ((-n + 2 * i + 1)*x[i]%modulo);
		sumx %= modulo;
	}
	for (int i = 0; i < m; i++) {
		sumy += ((-m + 2 * i + 1)*y[i]%modulo);
		sumy %= modulo;
	}
	cout << (sumx * sumy)%modulo << endl;
	return 0;
}