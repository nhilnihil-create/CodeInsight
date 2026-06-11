#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int l[n];
    for(int i=0;i<n;i++)cin >> l[i];
    sort(l,l+n);
    int ans=0;
    for(int i=n-k;i<n;i++)ans+=l[i];
    cout << ans;
}