
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;
    cin >> n;
    int64_t ans=1;
    for(int i = 1; i<=n;i++){
        ans = ans * i % 1000000007;
    }
    cout << ans % (1000000007) << endl;
}