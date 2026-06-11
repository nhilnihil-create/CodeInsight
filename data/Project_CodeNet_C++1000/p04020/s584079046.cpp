#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n,ans=0,cnt=0;
    cin >> n;
    long a[n];
    rep(i,n) cin >> a[i];
    rep(i,n){
       if(a[i]!=0) cnt += a[i];
       if(a[i]==0||i==n-1){
           ans += cnt/2;
           cnt = 0;
       }
    }
    cout << ans << endl;
}