#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	double ans = 0.0;
	int ans_w = 0, ans_s = 0;
	for (int a = 0; a <= F / 100 / A; a++) {
		for (int b = 0; b <= F / 100 / B; b++) {
			int water = a * 100 * A + b * 100 * B;
			for (int c = 0; c <= (water / 100)* E / C; c++) {
				for (int d = 0; d <= (water / 100) * E / D; d++) {
					int sugar = c * C + d * D;
					//cout << water << " " << sugar << endl;
					if (water + sugar > F || sugar > E * water / 100) continue;
					if ((double)sugar / (water + sugar) > ans) {
						ans = (double)sugar / (water + sugar);
						ans_w = water;
						ans_s = sugar;
					}
				}
			}
		}
	}
	if (ans_w == 0) ans_w = 100 * A;
	cout << ans_w + ans_s << " " << ans_s << endl;
}
