#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
#define PP std::pair<LL,int>
LL W, H;
LL SW[100010], SH[100010];
std::vector<PP> P;
LL ans;
LL a[2];
int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cin >> W >> H;
	a[0] = W + 1, a[1] = H + 1;
	for (int i = 0; i < W; i++) {
		LL tmp;
		std::cin >> tmp;
		P.emplace_back(PP{ tmp,0 });
	}
	for (int i = 0; i < H; i++) {
		LL tmp;
		std::cin >> tmp;
		P.emplace_back(PP{ tmp,1 });
	}
	std::sort(P.begin(), P.end());
	for (auto u : P) {
		a[u.second]--;
		ans += u.first*a[(u.second + 1) & 1];
	}
	std::cout << ans << std::endl;
	return 0;
}