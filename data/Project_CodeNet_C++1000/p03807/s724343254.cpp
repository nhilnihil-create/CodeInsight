#include <bits/stdc++.h>
using namespace std;
int main(){
     int n;
     long long a[100005];
     cin >> n;
     long long ans=0;
     for (int i=1;i<=n;i++){
        cin >> a[i];
        ans+=a[i];
     }
     if (ans%2==0) cout << "YES\n";
     else cout << "NO\n";
}