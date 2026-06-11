#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();

    vector<int> s(N+1), t(M+1);
    for(int i=0; i<N; i++) {
        if(S[i] == 'A') {
            s[i+1] = 1;
        } else {
            s[i+1] = 2;
        }
    }
    for(int i=0; i<M; i++) {
        if(T[i] == 'A') {
            t[i+1] = 1;
        } else {
            t[i+1] = 2;
        }
    }

    partial_sum(s.begin(), s.end(), s.begin());
    partial_sum(t.begin(), t.end(), t.begin());

    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((s[b] - s[a-1])%3 == (t[d] - t[c-1])%3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
