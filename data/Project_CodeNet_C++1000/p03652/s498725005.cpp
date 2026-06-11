#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;

int main() {
    int N, M;
    cin >> N >> M;
    queue<int> A[300];
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            int a;
            cin >> a;
            A[i].push(a - 1);
        }
    }

    vector<bool> K(M, true);
    int res = 1001001001;
    for(int j=M; j>0; ) {
        vector<int> S(M, 0);
        for(int i=0; i<N; ++i) {
            while(!K[A[i].front()]) A[i].pop();
            ++S[A[i].front()];
        }

        int tmp = *max_element(S.begin(), S.end());
        res = min(res, tmp);
        for(int k=0; k<M; ++k) {
            if(S[k] == tmp) {
                K[k] = false;
                --j;
            }
        }
    }

    cout << res << endl;
}