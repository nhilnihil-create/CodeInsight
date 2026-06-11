#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() { 
    int N, L;
    string s;
    cin >> N >> L;
    vector<string> S(N);
    rep(i, N) {
        cin >> s;
        S.push_back(s);
    }
    stable_sort(S.begin(), S.end());
    for(string i: S) {
        cout << i ;
    }
    cout << "\n";
    return 0;
}
