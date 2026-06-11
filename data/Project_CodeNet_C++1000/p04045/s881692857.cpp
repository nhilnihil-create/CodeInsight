#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<bool> d(10, false);
    for (auto i = 0; i < k; i++) { int a; cin >> a; d[a] = true; }
    for (auto i = n; i < 100000; i++) {
        int tmp = i;
        while(tmp > 0) {
            if(d[tmp % 10]) break;
            tmp /= 10;
        }
        if(tmp == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}