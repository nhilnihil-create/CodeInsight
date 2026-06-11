#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& e : v) {
        is >> e;
    }
    return is;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    constexpr int MAX = 100000;
    vector<int> num(MAX + 1, 0);
    vector<int> mnum(M, 0);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        num[X[i]]++;
        mnum[X[i] % M]++;
    }
    vector<int> pnum(M);
    for (int i = 0; i <= MAX; i++) {
        num[i] /= 2;
        pnum[i % M] += num[i];
    }

    if (M == 1) {
        cout << N / 2 << endl;
        return 0;
    } else {
        ll sum = 0;
        for (int i = 0; i + i <= M; i++) {
            if ((i + i) % M == 0) {
                sum += mnum[i] / 2;
            } else {
                if (mnum[i] < mnum[M - i]) {
                    sum += mnum[i];
                    const int res = (mnum[M - i] - mnum[i]) / 2;
                    sum += min(res, pnum[M - i]);
                } else {
                    sum += mnum[M - i];
                    const int res = (mnum[i] - mnum[M - i]) / 2;
                    sum += min(res, pnum[i]);
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
