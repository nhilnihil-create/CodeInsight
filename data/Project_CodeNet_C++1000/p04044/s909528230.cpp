#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, L;
    cin >> N >> L;

    vector<string> s(N);
    rep (i,N) {
        cin >> s.at(i);
    }
    sort(s.begin(), s.end());

    for (int i = 0; i < N; ++i) {
        cout << s.at(i);
    }
    cout << endl;


}
