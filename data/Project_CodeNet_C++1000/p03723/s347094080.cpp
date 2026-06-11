#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,C;
    cin >> A >> B >> C;
    if(A == B && B == C && A%2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    if(A%2 == 1 || B%2 == 1 || C%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    int i = 1;
    while(true) {
        int X = A,Y = B,Z = C;
        A = (Y+Z)/2;
        B = (X+Z)/2;
        C = (X+Y)/2;
        if(A%2 == 1 || B%2 == 1 || C%2 == 1) {
            cout << i << endl;
            return 0;
        }
        i++;
    }
}
