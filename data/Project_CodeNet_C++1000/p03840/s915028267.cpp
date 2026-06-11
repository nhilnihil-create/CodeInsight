#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int64_t> A(7);
    copy_n(istream_iterator<int64_t>(cin), 7, A.begin());
    int64_t I = A[0], O = A[1], J = A[3], L = A[4];

    int64_t ans = O * 2;
    int64_t mi = min({1L, I, L, J});
    ans += max(mi * 6 + (L - mi) / 2 * 4 + (J - mi) / 2 * 4 + (I - mi) / 2 * 4, L / 2 * 4 + J / 2 * 4 + I / 2 * 4);

    cout << ans / 2 << endl;
}
