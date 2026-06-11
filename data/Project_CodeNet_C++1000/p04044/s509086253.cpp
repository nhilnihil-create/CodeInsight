#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> a(N);

    rep(i,N) {
        string S;
        cin >> S;
        a.at(i) = S; 
    }

    string lib;
    rep (i, N) {
        sort(a.begin(), a.end());
        lib += a.at(i);
    }
    cout << lib << endl;

    return 0;
}