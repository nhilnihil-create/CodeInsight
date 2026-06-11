#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

long long a[MAX+1];

void solve() {
    int n;
    long long ai, bi, k, cnt;
    cin >> n >> k;
    cnt = 0;
    for (int i=0; i<n; ++i) {
        cin >> ai >> bi;
        a[ai] += bi;
    }
    for (int i =1 ; i <= MAX; ++i) {
        cnt += a[i];
        if (cnt >= k) {
            cout << i;
            return;
        }
    }

}

int main() {

    solve();
    return 0;
}
