#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int h, w, k; cin >> h >> w >> k;

	for(int i = 0; i <= h; i++) {
		for(int j = 0; j <= w; j++) {

			if(i * j + (h - i) * (w - j) == k) {
				cout << "Yes" << endl;
				return 0;
			}

		}
	}
	cout << "No" << endl;

}