#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P; 
LL H, W, N, a, b, ans[10];
map<P, bool> mp1, mp2;
int main()
{
	cin >> H >> W >> N;
	ans[0] = (H - 2) * (W - 2);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		a--, b--;
		mp2[P(a, b)] = true;
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if (0 <= a - j && a - j <= H - 3 && 0 <= b - k && b - k <= W - 3)
					mp1[P(a - j, b - k)] = true;
	}
	for (map<P,bool>::iterator it = mp1.begin(); it != mp1.end(); it++) {
		int x = it->first.first, y = it->first.second;
		int count = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (mp2[P(x + i, y + j)]) count++;
		ans[0]--;
		ans[count]++;
	}
	for (int i = 0; i < 10; i++)
		cout << ans[i] << endl;
}