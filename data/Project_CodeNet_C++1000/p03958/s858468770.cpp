#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define int long long
int INF = 1e9+7;
signed main() {
    int K,T;
    cin >> K >> T;
    vector<int>a(T);
    for(int i = 0; i < T; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cout << max(0LL,a[T-1]-1-(K-a[T-1])) << endl;
}

