/*
      author : nishi5451
      created: 11.08.2020 00:51:17
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans=a+b;
    ans = min(b+c,ans);
    ans = min(c+a,ans);
    cout << ans << endl;
    return 0;
}