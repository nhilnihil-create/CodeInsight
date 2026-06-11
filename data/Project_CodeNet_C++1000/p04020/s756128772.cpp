#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans=0;
    int cnt=0;
    for(int i = 0; i < n; i++) {
        if(a[i]==0){
            ans+=cnt/2;
            cnt=0;
        }
        cnt+=a[i];
    }
    ans+=cnt/2;
    cout << ans << "\n";
    return 0;
}