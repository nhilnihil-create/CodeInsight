#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)


int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int ans = 1000000000;
    for (int i = -100; i <= 100; i++){
        int s = 0;
        rep(j, n){
            s += (a[j] - i) * (a[j] - i);
        }
        ans = min(s, ans);
    }
    cout << ans << endl;
}
