#include <iostream>
#include <algorithm>

using namespace std;

const int maxLen = 1e5+5;
int a[maxLen];

void solve() {
    int n;
    cin >> n;
    for (int i=0; i< n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    bool cnt1, cnt2;
    cnt1=cnt2 = false;
    int c,d;
    for (int i=n-1; i>=1; --i) {
        if (a[i] == a[i-1]) {
             if (!cnt1){
                 cnt1 = true;
                 i -= 1;
                 c = a[i];
             } else {
                cnt2 = true;
                d = a[i];
                break;
             }
        }
    }
    if (cnt1 && cnt2) {
        cout << (long long) c * d;
    } else {
         cout << 0;
    }

}

int main() {

	solve();
    return 0;
}
