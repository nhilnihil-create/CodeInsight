#include <bits/stdc++.h>
using namespace std;
#define BE(x) (x).begin(), (x).end()

int main() {
    int n, a;
    cin >> n;
    bool f = false;
    if (n & 1) f = true;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (f) {
            if (i & 1) b.push_back(a);
            else b.insert(b.begin(),a);
        }
        else {
            if (i & 1) b.insert(b.begin(),a);
            else b.push_back(a);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == n-1) printf("%d\n", b[i]);
        else printf("%d ", b[i]);
    }
}