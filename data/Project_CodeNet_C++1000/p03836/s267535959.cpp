#include <bits/stdc++.h>
using namespace std;
// 0 0 1 2
int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    for(int i = 0; i < D-B; i++) {
        cout << 'U';
    }
    for(int i = 0; i < C-A; i++) {
        cout << 'R';
    }
    for(int i = 0; i < D-B; i++) {
        cout << 'D';
    }
    for(int i = 0; i < C-A+1; i++) {
        cout << 'L';
    }
    for(int i = 0; i < D-B+1; i++) {
        cout << 'U';
    }
    for(int i = 0; i < C-A+1; i++) {
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    for(int i = 0; i < D-B+1; i++) {
        cout << 'D';
    }
    for(int i = 0; i < C-A+1; i++) {
        cout << 'L';
    }
    cout << 'U';
    cout << endl;
}
