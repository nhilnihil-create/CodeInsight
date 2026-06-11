#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N, X;
    cin >> N >> X;

    if (X == 1 || X == 2 * N - 1) {
        puts("No");
        return 0;
    }

    deque<int> ans;
    ans.push_back(X);

    vector<bool> used(2*N);
    used[X] = true;
    bool flg = true;
    rep(i, N) {
        if (flg) {
            if (!used[i+1])     ans.push_front(i+1);
            used[i+1] = true;
            if (!used[2*N-1-i]) ans.push_back(2*N-1-i);
            used[2*N-1-i] = true;
        } else {
            if (!used[2*N-1-i]) ans.push_front(2*N-1-i);
            used[2*N-1-i] = true;
            if (!used[i+1])     ans.push_back(i+1);
            used[i+1] = true;
        }
        flg = 1 - flg;
    }

    puts("Yes");
    for (auto &i : ans) cout << i << endl;
}