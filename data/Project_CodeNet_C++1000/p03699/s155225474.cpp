#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x%10 > 0) {
            a.push_back(x);
            sum2 += x;
        }
        else {
            sum += x;
        }
    }
    if(a.size() == 0) {
        cout << 0;
    }
    else {
        int x = 0;
        sort(a.begin(), a.end());
        int i = 0;
        while((sum2 - x)%10 == 0) {
           x = a[i];
           i++;
        }
        cout << sum + sum2 - x;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
