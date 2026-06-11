/*
      author : nishi5451
      created: 10.08.2020 23:47:28
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    int ans;
    if(n<=k) ans = x*n;
    else ans = x*k + (n-k)*y;
    cout << ans << endl;
    return 0;
}