#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N;
    int64_t A, B;
    cin >> N >> A >> B;
    vector<int64_t> X(N);
    for(int i=0; i<N; i++) {
        cin >> X[i];
    }

    int64_t ans = 0;
    adjacent_difference(X.begin(), X.end(), X.begin());
    for(int i=1; i<N; i++) {
        ans += min(X[i]*A, B);
    }

    cout << ans << endl;
    return 0;
}
