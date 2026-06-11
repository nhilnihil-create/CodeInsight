/*
      author  : nishi5451
      created : 14.08.2020 14:59:22
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    rep(i,n){
        int x;
        cin >> x;
        ans += 2*min(x,k-x);
    }
    cout << ans << endl;
    return 0;
}