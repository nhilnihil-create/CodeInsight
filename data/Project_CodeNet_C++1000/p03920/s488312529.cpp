#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int INF = 1e10;
const int ZERO = 0;

signed main() {
	int N;
	cin >> N;
	vector<int> vec;
	int cnt = 0;
	int cnt2;
	for(int i = 1;i <= N;i++) {
		cnt += i;
		if(cnt >= N) {
			cnt2 = i;
			break;
		}
	}
	if(cnt == N) {
		for(int i = 1;i <= cnt2;i++) {
			cout << i << endl;
		}
	}
	else {
		cnt = cnt - N;
		for(int i = 1;i <= cnt2;i++) {
			if(i == cnt) {
				continue;
			}
			cout << i << endl;
		}
	}
}