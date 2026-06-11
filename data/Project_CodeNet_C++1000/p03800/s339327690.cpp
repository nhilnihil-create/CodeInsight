#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

void printans(vector<int> v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] == 0) cout << 'S';
        else        cout << 'W';
    }
    cout << endl;
}

int main(){
    int N;
    string s;
    cin >> N >> s;

    vector<int> v(N + 1);

    rep(i, 4) {
        v[0] = i & 1;
        v[1] = (i >> 1) & 1;
        for(int j = 2; j <= N; ++j) {
            int res;
            if ((v[j - 1] == 0 && s[j - 1] == 'o') || (v[j - 1] == 1 && s[j - 1] == 'x')) {
                res = v[j - 2];
            } else {
                res = 1 - v[j - 2];
            }
            v[j] = res;
        }

        // rep(i, N + 1) cout << v[i] << ", ";
        // cout << endl;

        if (v[0] == v[N]) {
            if ((v[0] == 0 && s[0] == 'o') || (v[0] == 1 && s[0] == 'x')) {
                if (v[1] == v[N - 1]) {
                    printans(v);
                    return 0;
                }
            } else {
                if (v[1] != v[N - 1]) {
                    printans(v);
                    return 0;
                }
            }
        }
    }
    cout << "-1" << endl;
}