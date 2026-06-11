#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    int ans;
    rep(i,n) {
        int x; cin >> x;
        ans += min(x, abs(x-k));
    }
    cout << ans*2 << endl;
}