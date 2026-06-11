#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    ll pre=0,ans=1e18;
    for(int i=0;i<n-1;i++){
        pre+=a[i];
        ans=min(ans,abs(2*pre-sum));
    }
    cout << ans << endl;
    return 0;
}