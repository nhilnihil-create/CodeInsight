#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,ans=0;
    cin >> n;
    int a[n];
    rep(i,n){
        cin >> a[i];
        a[i]--;
    } 
    rep(i,n){
        if(i==a[a[i]]) ans++;
    }
    cout << ans/2 << endl;
}