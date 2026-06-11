#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ret = 0; cin >>n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int t; cin >>t;
        a[t] += 1;
        ret += (a[t]%2==1) ? 1 : -1;
    }
    cout << ret << endl;
    return 0;
}