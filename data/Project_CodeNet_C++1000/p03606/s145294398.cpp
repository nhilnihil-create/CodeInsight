#include <iostream>
using namespace std;


int main()
{
	int N = 0, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> r >> l;

		if (r < l) {
			ans = ans + (l - r) + 1;
		}

		else if (r == l) {
			ans++;
		}
	}

	cout << ans << endl;
    
}