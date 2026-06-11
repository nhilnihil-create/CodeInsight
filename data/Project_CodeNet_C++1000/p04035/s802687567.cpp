#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n, l, psum = 0, idx, curr, prev;
    cin >> n >> l >> prev;
    for (int i = 1; i < n; ++i) {
        cin >> curr;
        if (curr + prev > psum) {
            psum = curr + prev;
            idx = i;
        }
        prev = curr;
    }
    if (psum >= l) {
        cout << "Possible" << endl;
        for (int i = 1; i < idx; ++i) {
            cout << i << endl;
        }
        for (int i = n-1; i > idx; --i) {
            cout << i << endl;
        }
        cout << idx << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
	return 0;
}
