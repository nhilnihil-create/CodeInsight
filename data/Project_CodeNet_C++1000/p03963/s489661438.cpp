/*
      author : nishi5451
      created: 12.08.2020 17:09:17
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    ll ans = k;
    n--;
    while(n--){
        ans*=(k-1);
    }
    cout << ans << endl;
    return 0;
}