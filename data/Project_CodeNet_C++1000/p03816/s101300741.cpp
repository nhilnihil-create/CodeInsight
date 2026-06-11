#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int dup=0;
    for(int i = 1; i < n; i++) {
        if(a[i]==a[i-1]) dup++;
    }
    int ans=n-dup;
    if(dup%2!=0) ans--;
    cout << ans << "\n";
    return 0;
}