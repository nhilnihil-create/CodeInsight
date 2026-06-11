#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans[100][100];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			ans[sum / w][sum % w] = i;
			sum++;
		}
	}
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0)
			for (int j = 0; j < w; j++)
				cout << ans[i][j] << " ";
		else
			for (int j = w - 1; j >= 0; j--)
				cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}