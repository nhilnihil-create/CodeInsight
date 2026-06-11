#include<bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	
    int ans = 2000000000;
	for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int tx = (i ? -x : x);
            int ty = (j ? -y : y);
            if (tx <= ty) {
                if (i + j + ty - tx < ans) {
                    ans = i + j + ty - tx;
                }
            }
        }
    }

    cout << ans << endl;
	return 0;
}
