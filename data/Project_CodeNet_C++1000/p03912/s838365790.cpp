#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> x(N);
    vector<int> m(M);
    int ans = 0;
    for(int i=0; i<N; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    for(int i=0; i<N; ++i) {
        m[x[i] % M]++;
    }
    for(int i=1; i<N;) {
        if(x[i] % M != 0 && x[i] == x[i-1] && m[x[i] % M] > m[M - (x[i] % M)] ) {
            ans++;
            m[x[i] % M] -= 2;
            i += 2;
        } else {
            i++;
        }
    }
    ans += m[0]/2;
    for(int i=1; i<M/2 + (M%2 == 0 ? 0 : 1); ++i) {
        ans += min(m[i], m[M-i]);
    }
    if(M % 2 == 0) {
        ans += m[M/2]/2;
    }
    cout << ans << endl;
}
