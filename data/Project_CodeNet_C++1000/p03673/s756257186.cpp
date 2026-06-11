#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<int> d;
    if(n == 1) {
        cout<< a[0] << endl;
        return 0;
    }
    else if(n == 2) {
        cout << a[1] << ' ' << a[0] << endl;
        return 0;
    }
    else if(n % 2 == 0) {
        d.push_back(a[1]);
        d.push_back(a[0]);
        for(int i = 2; i < n; i++) {
            i % 2 == 0 ? d.push_back(a[i]) : d.push_front(a[i]);
        }
    }
    else {
        d.push_back(a[0]);
        for(int i = 1; i < n; i++) {
            i % 2 == 0 ? d.push_front(a[i]) : d.push_back(a[i]);
        }
    }
    rep(i, n) cout << d[i] << ' ';
}
