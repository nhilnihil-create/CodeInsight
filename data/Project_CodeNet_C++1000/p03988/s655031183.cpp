#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e2 + 13;
int n, cnt[maxN], mx;
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	cnt[a]++;
	mx = max(mx, a);
    }

    if (mx % 2 == 1) {
	int num = 0;
	if (cnt[mx / 2 + 1] != 2)
	    return cout << "Impossible" << endl, 0;
	for (int i = mx / 2 + 1; i <= mx; i++) {
	    num += cnt[i];
	    if (cnt[i] < 2)
		return cout << "Impossible" << endl, 0;
	}
	if (num != n)
	    return cout << "Impossible" << endl, 0;
	cout << "Possible" << endl;
    }

    else {
	int num = 1;
	if (cnt[mx / 2] != 1)
	    return cout << "Impossible" << endl, 0;
	for (int i = mx / 2 + 1; i <= mx; i++) {
	    num += cnt[i];
	    if (cnt[i] < 2)
		return cout << "Impossible" << endl, 0;
	}
	if (num != n)
	    return cout << "Impossible" << endl, 0;
	    
	cout << "Possible" << endl;
    }
}
