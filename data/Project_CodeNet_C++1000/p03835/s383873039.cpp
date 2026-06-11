#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    int K, S;
    cin >> K >> S;
    ll ans = 0;
    for(int x = 0; x <= K; x++){
        for(int y = 0; y <= K; y++){
            int val = S - (x + y);
            if(val >= 0 && val <= K) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
