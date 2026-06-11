#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define LL long long
#define PP std::pair<int,int>
LL N;
LL H, W;
LL ans[10];
int D[] = { -1,0,1 };
std::set<PP> B;
std::vector<PP> cen;
int main() {
	std::cin >> H >> W >> N;
	ans[0] = (H - 2)*(W - 2);
	for (int i = 0; i < N; i++) {
		int a, b;
		std::cin >> a >> b;
		B.insert({ a,b });
		for (auto u : D) {
			for (auto m : D) {
				if (1 < a + u&&a + u < H && 1 < b + m&&b + m < W) {
					cen.push_back({ a + u,b + m });
				}
			}
		}
	}
	std::sort(cen.begin(), cen.end());
	cen.erase(std::unique(cen.begin(), cen.end()), cen.end());
	for (auto u : cen) {
		int count = 0;
		for (auto dx : D) {
			for (auto dy : D) {
				auto it = B.find({ u.first + dx,u.second + dy });
				if (it != B.end()) {
					count++;
				}
			}
		}
		ans[count]++;
		ans[0]--;
	}
	for (int i = 0; i <= 9; i++) {
		std::cout << ans[i] << std::endl;
	}
	return 0;
}