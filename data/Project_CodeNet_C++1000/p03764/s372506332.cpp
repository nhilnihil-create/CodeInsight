#include<iostream>
int n, m;
long long x[100000], y[100000];
long long  ansx, ansy;
int waru = 1000000000+7;
long long ans;
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	for (int j = 0; j < m; j++) {
		std::cin >> y[j];
	}
	for (int i = 1; i <= n; i++) {
		ansx = ((i + i - n - 1)*x[i - 1] + ansx) % waru;
	}
	for (int i = 1; i <= m; i++) {
		ansy = ((i + i - m - 1)*y[i - 1] + ansy) % waru;
	}
	ans = (ansx*ansy) % waru;
	std::cout << ans << std::endl;
	return 0;
}