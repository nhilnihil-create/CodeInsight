#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    bool can = false;
    for(int i=0;i<=m;i++){ //たて
        for(int j=0;j<=n;j++){ //よこ
            int on = i*(n-j)+j*(m-i);
            if(on==k) can = true;
        }
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}

