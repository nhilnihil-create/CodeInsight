#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
using namespace std;

int main() {
    int n, ans=0; cin >> n;
    int a[n];
    rep(i,1,n+1){
        cin >> a[i];
    }
    rep(i, 1, n+1) {
        if(a[i] == i){
            swap(a[i],a[i+1]);
            ans++;
        }
    }
    cout << ans << endl;
}