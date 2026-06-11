#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>T(N);
    vector<int>A(N);
    vector<int>cnt(N,-1);
    vector<int>ika(N,-1);
    int sum = -1;
    for(int i = 0; i < N; i++) {
        cin >> T[i];
        if(T[i] > sum) {
            cnt[i] = T[i];
            sum = T[i];
        }
        else {
            ika[i] = T[i];
        }
    }
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(i+1 == N) {
            if(cnt[i] != A[i] && cnt[i] != -1) {
                cout << 0 << endl;
                return 0;
            }
            else {
                cnt[i] = A[i];
            }
        }
        if(i != 0){
            if(A[i-1] > A[i]) {
                if(cnt[i-1] != A[i-1] && cnt[i-1] != -1) {
                    cout << 0 << endl;
                    return 0;
                }
                else {
                    cnt[i-1] = A[i-1];
                }
            }
            if(cnt[i-1] == -1) {
                ika[i-1] = min(ika[i-1],A[i-1]);
            }
            if(cnt[i-1] != -1 && ika[i-1] != -1 && cnt[i-1] > ika[i-1]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < N; i++) {
        if(cnt[i] == -1) {
            ans*=ika[i];
            ans%=INF;
        }
    }
    cout << ans << endl;
}
