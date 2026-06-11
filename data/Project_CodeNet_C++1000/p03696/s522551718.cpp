#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main(){
    int N;
    string S;
    cin >> N >> S;
    int l = 0;int r = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == ')') {
            if(r > 0) {
                r--;
            }
            else {
                l++;
            }
        }
        else {
            r++;
        }
    }
    for(int i = 0; i < l; i++) {
        cout << '(';
    }
    cout << S;
    for(int i = 0; i < r; i++) {
        cout << ')';
    }
    cout << endl;
}