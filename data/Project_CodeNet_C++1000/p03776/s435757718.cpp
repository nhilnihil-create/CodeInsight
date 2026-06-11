#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int64_t comb(int n, int r) {
    int64_t res = 1;
    for(int i=0; i<r; i++) {
        res *= n-i;
        res /= i+1;
    }
    return res;
}

int main(void) {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int64_t> v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());

    cout << fixed << accumulate(v.begin(), v.begin()+A, 0.0) / (double)A << endl;

    bool isAllSame = true;
    for(int i=1; i<A; i++) {
        if(v[i] != v[i-1]) {
            isAllSame = false;
        }
    }

    if(isAllSame) {
        int cnt = count(v.begin(), v.end(), v[0]);
        int64_t ans = 0;
        for(int i=A; i<=min(B, cnt); i++) {
            ans += comb(cnt, i);
        }
        cout << ans << endl;
    } else {
        int cnt = count(v.begin(), v.end(), v[A-1]);
        int lrg = count_if(v.begin(), v.end(), [&](int64_t x) {return x > v[A-1];});
        cout << comb(cnt, A-lrg) << endl;
    }

    return 0;
}
