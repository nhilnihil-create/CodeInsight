#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N,L;
    cin >> N >> L;
    vector<int>a(N);
    vector<int>ans;
    int sum = 0,res = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(i) {
            if(sum < a[i]+a[i-1]) {
                res = i;
                sum = a[i]+a[i-1];
            }
        }
    }
    if(sum < L) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(int i = 1; i < res; i++) {
        cout << i << endl;
    }
    for(int i = N-1; i >= res; i--) {
        cout << i << endl;
    }
}