#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<int>cnt(a[n-1]+10,0);
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    int ans=0;
    for(int i=0;i<=a[n-1];i++){
        ans = max(ans,cnt[i-1]+cnt[i]+cnt[i+1]);
    }
    cout << ans << endl;
}
