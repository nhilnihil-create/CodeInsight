#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007


char c[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main() {
	int H, W;
	cin >> H >> W;
	string ans;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			string s;
			cin >> s;
			if (s == "snuke") {
				ans += c[j]; ans += to_string(i);
			}


		}
	}

	print(ans);




	return 0;
}