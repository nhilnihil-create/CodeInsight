#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
LL W, H;
LL SW[100010], SH[100010];
std::vector<LL> PW, PH;
LL ans;
int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cin >> W >> H;
	for (int i = 0; i < W; i++) {
		LL tmp;
		std::cin >> tmp;
		PW.emplace_back(tmp);
	}
	for (int i = 0; i < H; i++) {
		LL tmp;
		std::cin >> tmp;
		PH.push_back(tmp);
	}
	std::sort(PW.begin(), PW.end());
	std::sort(PH.begin(), PH.end());
	for (int i = 1; i <= W; i++) {
		SW[i] += SW[i - 1] + PW[i - 1];
	}
	for (int i = 1; i <= H; i++) {
		SH[i] += SH[i - 1] + PH[i - 1];
	}
	ans += SW[W] + SH[H];
	for (int i = 0; i < W; i++) {
		auto it = std::upper_bound(PH.begin(), PH.end(), PW[i]);
		LL K = it - PH.begin();
		ans += SH[K] + PW[i] * (H - K);
	}
	std::cout << ans << std::endl;
	return 0;
}
