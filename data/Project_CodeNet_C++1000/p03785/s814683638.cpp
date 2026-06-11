#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    rep(i, N) cin >> T[i];
    sort(T.begin(), T.end());
    int bus = 0;
    for (int i = 0; i < N;)
    {
        int j = i;
        int p = 0;
        while (T[j] <= T[i] + K && p < C)
        {
            j++;
            p++;
        }
        i += p;
        bus++;
    }
    cout << bus << endl;
    return 0;
}