#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    REP(i, N) REP(j, M) {
        cin >> A[i][j];
        --A[i][j];
    }
    
    int result = N;
    vector<bool> is_open(M, true);
    int n_opens = M;
    while (n_opens >= 2) {
        vector<int> cnt(M);
        REP(i, N) {
            REP(j, M) {
                if (is_open[A[i][j]]) {
                    cnt[A[i][j]]++;
                    break;
                }
            }
        }
        int k = max_element(all(cnt)) - cnt.begin();
        amin(result, cnt[k]);
        is_open[k] = false;
        --n_opens;
    }

    cout << result << endl;

    return 0;
}
