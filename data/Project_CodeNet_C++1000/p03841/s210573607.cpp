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
    vector<P>x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i].first;
        x[i].second = i;
        x[i].first--;
    }
    sort(x.begin(),x.end());
    vector<int>ans(N*N);
    for(int i = 0; i < N; i++) {
        ans[x[i].first] = x[i].second+1;
        int X = x[i].second;
        for(int j = 0; j < x[i].first; j++) {
            if(!X) {
                break;
            }
            if(ans[j]) {
                continue;
            }
            ans[j] = x[i].second+1;
            X--;
        }
    }
    for(int i = N-1; i >= 0; i--) {
        int X = N-x[i].second-1;
        for(int j = N*N-1; j > x[i].first; j--) {
            if(!X) {
                break;
            }
            if(ans[j]) {
                continue;
            }
            ans[j] = x[i].second+1;
            X--;
        }
    }
    for(int i = 1; i <= N; i++) {
        int X = 0;
        bool ok = false;
        for(int j = 0; j < N*N; j++) {
            if(ans[j] == x[i-1].second+1) {
                X++;
            }
            if(X == x[i-1].second+1) {
                if(j == x[i-1].first) {
                    ok = true;
                }
            }
        }
        if(X != N) {
            ok = false;
        }
        if(!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < N*N; i++) {
        if(i) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}