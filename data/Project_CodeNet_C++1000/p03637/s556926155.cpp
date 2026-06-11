#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a.at(i);
    int cnt_4 = 0;
    int cnt_odd = 0;
    rep(i,N) {
        if (a.at(i) % 4 == 0) ++cnt_4;
        else if (a.at(i) % 2 == 1) ++ cnt_odd;
    }
    if (cnt_4 >= cnt_odd
    || (cnt_4 + cnt_odd == N && cnt_4 + 1 == cnt_odd)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
