#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    vector<int> A(100003,0); // -1 to 100001
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; ++t; // t = 0 の場合を考慮する
        A[t-1]++;
        A[t]++;
        A[t+1]++;
    }
    int ret = 0;
    for (int i = 0; i < 100003; i++) ret = max(ret, A[i]);
    cout << ret << endl;
    return 0;
}