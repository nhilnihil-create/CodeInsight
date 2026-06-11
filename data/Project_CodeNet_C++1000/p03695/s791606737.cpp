#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> dist(9, 0);
	for (int i = 0; i < N; i++) {
		int rate;
		scanf("%d", &rate);
		if (rate < 3200) {
			for (int j = 7; j >= 0; j--) {
				if (rate >= j * 400) {
					dist.at(j)++;
					break;
				}
			}
		} else {
			dist.at(8)++;
		}
	}

	int min_col = 0;
	for (int i = 0; i < 8; i++) {
		min_col += dist.at(i) > 0;
	}
	printf("%d %d\n", min_col == 0 ? 1 : min_col, min_col + dist.at(8));
	return 0;
}
