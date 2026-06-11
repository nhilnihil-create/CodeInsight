#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
  	cin >> n >> k;
  	vector<int> v(n);
  	rep(i, n) {
    	cin >> v.at(i);
    }
  	sort(v.begin(), v.end(), greater<int>());
  	int sum = 0;
  	rep(i, k) {
    	sum += v[i];
    }
  	cout << sum << endl;
    return 0;
}