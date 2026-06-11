#include<iostream>
#include<algorithm>

using namespace std;

int N, T;
int in[100001];

int main() {

	cin >> N >> T;
	for (int i = 0; i < N; i++)cin >> in[i];
	int ct = 1, biggest = -1, small = in[0];
	int ans = 0;
	int beforesmall = 0;
	for (int i = 1; i <= N; i++) {
		beforesmall = small;
		small = min(small, in[i]);
		if (i != N && in[i] > in[i - 1])ct++;
		else {
			if (ct != 0) {
				if (biggest == in[i - 1] - beforesmall) {
					ans++;
				}
				else if (biggest < in[i - 1] - beforesmall) {
					biggest = in[i - 1] - beforesmall;
					ans = 1;
				}
				ct = 0;
			}
		}
		//cout << i << " " << biggest << " " << small << endl;
	}

	cout << ans << endl;

	return 0;
}