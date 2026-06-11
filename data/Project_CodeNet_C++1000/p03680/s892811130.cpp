#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        if (x == 1) {
            count = i;
            break;
        }
        x = a[x];
    }
    if (count!=0) {
        cout << count << endl;
    }
    else {
        cout << -1 << endl;
    }
}