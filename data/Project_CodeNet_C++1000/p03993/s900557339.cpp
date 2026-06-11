#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int ans = 0;
    map<pair<int, int>, bool> r;
    for(int i = 0; i < N; i++) {
        //cout << i << endl;
        int a, b;
        cin >> a;
        b = i + 1;
        pair<int, int> p = make_pair(min(a, b), max(a, b));
        //cout << "##" << endl;
        if(r.count(p)) {
            ans++;
            r.erase(p);
        } else {
            r[p] = 1;
        }
    }
    cout << ans << endl;

    return 0;
}