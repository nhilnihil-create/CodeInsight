#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n];
    rep(i,n) cin >> a[i];
    long long now = 1;
    long long ans = a[0]-1;
    for(int i = 1;i<n;i++){
        if(a[i]==now+1) now++;
        else ans+=(a[i]-1)/(now+1);
    }
    cout << ans << endl;
}