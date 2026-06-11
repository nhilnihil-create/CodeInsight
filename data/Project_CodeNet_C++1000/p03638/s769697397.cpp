#include<iostream>
#include<vector>
#include<string>

int main() {
	int h, w, n;
	std::cin >> h >> w >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)std::cin >> a[i];
	std::vector<std::vector<int>>s(h, std::vector<int>(w));
	int count = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			s[i][j] = count;
			a[count - 1]--;
			if (a[count - 1] == 0) {
				count++;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i % 2)printf("%d ", s[i][w - j - 1]);
			else printf("%d ", s[i][j]);
		}
		printf("\n");
	}
}