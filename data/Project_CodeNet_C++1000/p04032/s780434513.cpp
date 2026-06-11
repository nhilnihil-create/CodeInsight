#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    string S;
    cin >> S;
    for(int i = 0; i < (int)S.size()-1; i++) {
        if(S[i] == S[i+1]) {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
    }
    for(int i = 0; i < (int)S.size()-2; i+=2) {
        if(S[i] == S[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    for(int i = 1; i < (int)S.size()-2; i+=2) {
        if(S[i] == S[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}
