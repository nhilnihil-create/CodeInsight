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
	int X;
	cin >> X;
	int A = 1;
	int cnt = 0;
	for(int i = 1;i < 1000010;i++) {
		cnt += A;
		if(cnt >= X) {
			cout << i << endl;
			break;
		}
		A++;
	}
}