#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    rep(i, n){
        cin >> vec[i];
    }
    
    int ans = 0;
    rep(i, n){
        if(vec[i] < k - vec[i]){
            ans += vec[i] * 2;
        }else ans += abs(vec[i] - k) * 2;
    }
    
    cout << ans << endl;
}