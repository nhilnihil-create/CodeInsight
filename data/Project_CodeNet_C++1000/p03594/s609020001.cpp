#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

const int N = 1111;
const string colors = "YGRB";
string mat[N];
int h, w, d;

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cin >> h >> w >> d;
    for(int i = 0; i < N; i++) {
        mat[i] = "";
        for(int j = 0; j < N; j++) {
            int ii = i % (2 * d);
            int jj = j % (2 * d);
            bool iii = ii < d;
            bool jjj = jj < d;
            mat[i] += colors[iii * 2 + jjj];
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int ii = i + j;
            int jj = i - j + 500;
            cout << mat[ii][jj];
        }
        cout << endl;
    }
    return 0;
}