#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, t;
    cin >> k >> t;

    int max_a = 0;
    for (auto i = 0; i < t; i++) {
        int a; cin >> a; max_a = max(max_a, a);
    }
    cout << max(max_a - 1 - (k - max_a), 0) << endl;
    return 0;
}