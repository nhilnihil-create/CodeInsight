#include <bits/stdc++.h>
using namespace std;
// o o o o o o o o 
// 7 5 3 1 1 3 5 7
// o o o o o o o o o
// 8 6 4 2 0 2 4 6 8
#define int long long
int INF = 1e9+7;
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    if(N%2 == 0) {
        vector<int>cnt(100001,0);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
            if(A[i]%2 == 0) {
                cout << 0 << endl;
                return 0;
            }
            cnt[A[i]]++;
        }
        for(int i = 1; i <= N; i+=2) {
            if(cnt[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
        }
        int ans = 1;
        for(int i = 1;  i <= N/2; i++) {
            ans*=2;
            ans = ans%INF;
        }
        cout << ans << endl;
    }
    else {
        vector<int>cnt(100001,0);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
            if(A[i]%2 == 1) {
                cout << 0 << endl;
                return 0;
            }
            cnt[A[i]]++;
        }
        for(int i = 2; i < N; i+=2) {
            if(cnt[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
        }
        if(cnt[0] != 1) {
            cout << 0 << endl;
            return 0;
        }
        int ans = 1;
        for(int i = 1;  i <= N/2; i++) {
            ans*=2;
            ans = ans%INF;
        }
        cout << ans << endl;
    }
}