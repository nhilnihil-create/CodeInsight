#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> s(N);
    rep(i,N) cin >> s.at(i);
    sort(s.begin(), s.end());
    int sum = 0;
    rep(i,N) sum += s.at(i);
    if (sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    } else {
        rep(i,N) {
            if ((sum - s.at(i)) % 10 != 0) {
            cout << sum - s.at(i) << endl;
            return 0;
            } 
        }
        cout << 0 << endl;
        return 0;
    }
}

