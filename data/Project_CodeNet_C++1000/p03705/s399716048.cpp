#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,A,B;
    cin >> N >> A >> B;
    if(A > B) {
        cout << 0 << endl;
        return 0;
    }
    if(N == 1) {
        if(A == B) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    else {
        cout << A+B*(N-1)-(B+A*(N-1))+1 << endl;
    }
}
