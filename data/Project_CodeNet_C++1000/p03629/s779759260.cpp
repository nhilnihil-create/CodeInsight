#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
std::vector<int> alpha[26];
std::string S, ans;
bool had[26];
int suff[200010];
int main() {
	std::cin >> S;
	int sf = 0;
	int ac = 1;
	for (int i = S.size() - 1; i >= 0; i--) {
		alpha[S[i] - 'a'].emplace_back(i + 1);
		suff[i + 1] = ac;
		if (!had[S[i] - 'a']) {
			had[S[i] - 'a'] = true;
			sf++;
		}
		if (sf == 26) {
			for (int j = 0; j < 26; j++)had[j] = false;
			sf = 0;
			ac++;
		}
	}
	for (int i = 0; i < 26; i++) {
		alpha[i].emplace_back(S.size() + 1);
		std::sort(alpha[i].begin(), alpha[i].end());
	}
	int now = 0;
	suff[0] = ac;
	for (int i = 1; i <= ac; ac--) {
		for (int j = 0; j < 26; j++) {
			auto it = std::upper_bound(alpha[j].begin(), alpha[j].end(), now);
			if (suff[now] - 1 == suff[*it]) {
				ans += ('a' + j);
				now = *it;
				break;
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}