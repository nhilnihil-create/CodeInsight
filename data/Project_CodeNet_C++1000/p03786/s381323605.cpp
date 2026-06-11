#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int N;
vector<int> A;

int main(void) {
    cin >> N;
    A.assign(N, 0);
    rep(i, N) cin >> A[i];

    sort(ALLOF(A));
    vector<ll> Asums(N, 0);
    Asums[0] = A[0];
    REP(i, 1, N) {
        Asums[i] = Asums[i - 1] + A[i];
    }


    int ans = 0;
    for(int i = 0; i < N; ++i) {

        ll size = Asums[i];
        bool flag = false;
        auto beg_itr = A.begin() + i + 1;
        while(true) {
            // 条件を満たさない最初のidx
            auto itr = upper_bound(beg_itr, A.end(), size * 2);

            if (itr == A.end()) {
                flag = true;
                break;
            } 
            if (itr == beg_itr) {
                flag = false;
                break;
            }

            itr--;
            size = Asums[distance(A.begin(), itr)];
            beg_itr = itr + 1;
        }

        if (flag) {
            ans = N - i;
            break;
        }


    }

    cout << ans << endl;

    return 0;
}