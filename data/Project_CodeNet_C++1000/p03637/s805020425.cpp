#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    int cnt4, cnt2, cnt1;
    cnt1 = cnt2 = cnt4 = 0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int ai;
        cin >> ai;
        if (ai&1) {
            ++cnt1;
        } else if (ai % 4 == 0) {
            ++cnt4;
        } else  {
            ++cnt2;
        }
    }
    //cout << cnt1 << " " << cnt2 << " " << cnt4 << endl;
    if (cnt4 + 1 < cnt1) {
        cout << "No";
        return;
    } else {
        if (cnt2 == 0) {
            cout << "Yes";
            return;
        } else if (cnt4 < cnt1) {
            cout << "No";
        } else {
            cout << "Yes";
        }

    }

}

int main() {

	solve();
    return 0;
}
