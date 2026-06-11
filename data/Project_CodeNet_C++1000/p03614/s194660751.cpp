#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	int n, p;
	cin >> n;
	int m[100000] = {};
	for (int i = 0; i < n; i++) {
		cin >> p; if (i + 1 == p)m[i] = 1;
	}
	int count=0;
	for (int i = 0; i < n; i++) {
		if (m[i] == 1) {
			count++;
			if (i + 1 < n&&m[i + 1] == 1) {
				m[i + 1] = 0;
			}
		}
	}
	cout << count << endl;
	char nyaa;
	cin >> nyaa;
	return 0;
}