#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    string s, t;
    cin >> N >> s >> t;
    for(int i = 0; i < N + 1; i++) {
        if(s.substr(i, N - i) == t.substr(0, N - i)) {
            cout << N + i << endl;
            //cout << s << t.substr(N - i, i) << endl;
            return 0;
        }
    }

    return 0;
}