#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
#define int long long
#define mod(int)(1000000007)
using namespace std;
const int INF = 1000000000000;
vector<int> prime_factor(int num) {
    vector<int>res;
    while (num % 2 == 0) { // 偶数の素数は2のみ
        res.push_back(2);
        num /= 2;
    }
    for (int i = 3; i <= num; i++) { // 他の素数で割っていく
        while (num % i == 0) {
			res.push_back(i);
            num /= i;
        }
    }
    return res;
}
int cnt[345678];
signed main() {
	int n, m, ans = 1; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int h = 0; h < prime_factor(i).size(); h++) {
			cnt[prime_factor(i)[h]]++;
			//cout << i << ' ' << prime_factor(i)[h] << endl;
		}
	}
	for (int h = 2; h <= n; h++) {
		ans *= (cnt[h] + 1); ans %= 1000000007;
		//cout << cnt[h] << endl;
	}
	cout << ans % 1000000007 << endl;
	return 0;
}