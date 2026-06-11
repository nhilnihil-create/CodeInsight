#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    // - - - - o o
    // - - - x - o
    // - - o - - o
    // - x - - - o
    // o - - - - o  (1,1) (3,3)
    // o o o o
    // o o x o
    // o o o o
    // o x o o
    // o o o o
    for(int i = B+1; i <= D; i++) {
        cout << 'U';
    }
    for(int i = A+1; i <= C; i++) {
        cout << 'R';
    }
    for(int i = D-1; i >= B; i--) {
        cout << 'D';
    }
    for(int i = C-1; i >= A; i--) {
        cout << 'L';
    }
    cout << 'L';
    for(int i = B+1; i <= D+1; i++) {
        cout << 'U';
    }
    for(int i = A; i <= C; i++) {
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    for(int i = D-1; i >= B-1; i--) {
        cout << 'D';
    }
    for(int i = C; i >= A; i--) {
        cout << 'L';
    }
    cout << 'U';
    cout << endl;
    //UURRDDLLLUUURRDRDDDLLU
}
