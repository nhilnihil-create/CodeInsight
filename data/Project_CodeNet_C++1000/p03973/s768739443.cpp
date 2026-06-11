#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p = 1;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == p) p++;
        else if (p < a) {
            cnt += (long long)(a - 1) / p;
            if (p == 1) p++;
        }
    }

    cout << cnt << endl;
}