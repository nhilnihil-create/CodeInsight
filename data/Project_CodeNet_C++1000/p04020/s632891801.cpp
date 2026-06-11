#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n;
    cin >> n;
    long int a[n];
    rep(i, n) cin >> a[i];
    long int ans = 0;
    rep(i, n - 1){
        ans += a[i] / 2;
        a[i] -= (a[i] / 2) * 2;
        if (a[i+1] > 0){
            ans += a[i];
            a[i+1] -= a[i]; 
        }
        // cout << ans << endl;
    }
    ans += a[n-1] / 2;
    cout << ans << endl;
}
