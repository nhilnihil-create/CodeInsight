#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N;
int A[300][300];
int c[300][300];

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            c[i][j] = 0;
        }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bool cf = false;
            int aij = A[i][j];
            for (int k = 0; k < N; ++k) {
                if (k == i || k == j)
                    continue;
                int d = A[i][k] + A[j][k];
                if (d < aij) {
                    cout << -1 << endl;
                    return 0;
                }
                if (d == aij)
                    cf = true;
            }
            if (cf)
                c[i][j] = 1;
        }
    }

    long x = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (c[i][j] == 0)
                x += A[i][j];
        }
    }
    
        

    cout << x << endl;
    return 0;
}
