#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, m, n) for (int i = m; i < n; ++i)

class BIT {
private:
    vector<int> dat;
    int n;
public:
    BIT(int size) {
        dat.resize(size + 1);
        n = size;
    }
    int sum(int i) {
        int s = 0;
        while(i > 0) {
            s += dat[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        while(i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }
};

template<class T> vector<int> compress(const vector<T> &A) {
    int n = A.size();
    vector<T> B(n);
    vector<int> C(n);
    copy(A.begin(), A.end(), B.begin());
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for(int i = 0; i < n; ++i) {
        int id = lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1;
        C[i] = id;
    }
    return C;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
        A[i] -= K;
    }
    vector<ll> R(N + 1);
    rep(i, 0, N) R[i+1] = R[i] + A[i];
    vector<int> C = compress(R);
    ll ans = 0;
    BIT bit(N + 1);
    rep(i, 0, N + 1) {
        ans += bit.sum(C[i]);
        bit.add(C[i], 1);
    }
    cout << ans << endl;
    return 0;
}
