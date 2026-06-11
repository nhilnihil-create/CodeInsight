#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[100002];
signed main() {
    int N,K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        ans[a]+=b;
    }
    for(int i = 1; i <= 100000; i++) {
        if(K <= ans[i]) {
            cout << i << endl;
            return 0;
        }
        K-=ans[i];
    }
}