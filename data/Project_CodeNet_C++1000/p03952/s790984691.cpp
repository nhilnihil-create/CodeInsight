#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    
    if (x == 1 || x == 2*n-1) {
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    if (n == 2) {
        cout << "1\n2\n3\n";
        return 0;
    }
    
    int center[4];
    if (x == 2) {
        center[0] = 4;
        iota(center+1, center+4, 1);
    } else {
        iota(center, center+3, x-1);
        center[3] = x-2;
    }
    
    vector<int> ans(2*n-1);
    
    int c = 1;
    for (int i = 1; i <= 2*n-1; i++) {
        if (i >= n-1 && i <= n+2) continue;
        while (count(center, center+4, c)) c++;
        ans[i-1] = c;
        c++;
    }
    copy(center, center+4, ans.begin()+n-2);
    
    for (auto e: ans) cout << e << endl;

    
    return 0;
}
