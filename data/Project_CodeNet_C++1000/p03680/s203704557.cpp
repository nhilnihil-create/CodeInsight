#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int i, c=1, next, n;
    cin >> n;
    vector<int> d(n+1);

    for (i=1; i<=n; i++) {
        cin >> d[i];
    }

    next = d[1];
    while(next != 2) {
        next = d[next];
        c++;
        if (c == n) {
            c = -1;
            break;
        }
    }
    cout << c << endl;
}
