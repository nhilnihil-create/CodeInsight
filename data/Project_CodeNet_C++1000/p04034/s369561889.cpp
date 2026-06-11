#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> Num(N + 1, 1);
	vector<int> Red(N + 1);
	Red[1] = 1;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		Num[x]--;
		Num[y]++;
		if (Red[x] == 1) Red[y] = 1;
		if (Num[x] == 0) Red[x] = 0;
	}
	int ans = 0;
	for (int r : Red) ans += r;
	cout << ans << endl;

}
