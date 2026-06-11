#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector< vector<int> > A(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }

    auto B = A;
    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
            }
        }
    }

    if(A == B) {
        int64_t ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=i+1; j<N; j++) {
                bool flag = true;
                for(int k=0; k<N; k++) {
                    if(i == k || j == k) continue;
                    if(B[i][j] == B[i][k] + B[j][k]) flag = false;
                }
                if(flag) {
                    ans += B[i][j];
                }
            }
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
