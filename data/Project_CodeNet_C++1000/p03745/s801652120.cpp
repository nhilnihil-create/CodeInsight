#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int cnt = 0;
    int ans = 1;
    bool flag = true;
    bool horyuu = false;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(i == 1) {
            if(cnt > A[i]) {
                flag = false;
            }
        }
        else if(!horyuu){
            if(flag && cnt > A[i]) {
                ans++;
                horyuu = true;
            }
            else if(!flag && cnt < A[i]) {
                ans++;
                horyuu = true;
            }
        }
        else if(horyuu) {
            if(cnt < A[i]) {
                flag = true;
                horyuu = false;
            }
            if(cnt > A[i]) {
                flag = false;
                horyuu = false;
            }
        }
        cnt = A[i];
    }
    cout << ans << endl;
}