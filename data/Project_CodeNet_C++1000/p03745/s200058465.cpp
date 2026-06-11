#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n) {
        while(i+1 < n && a[i]==a[i+1]) ++i;
        if(i+1 < n && a[i] < a[i+1]) {
            while(i+1 < n && a[i] <= a[i+1]) ++i;
        }
        else if(i+1 < n && a[i] > a[i+1]) {
            while(i+1 < n &&  a[i] >= a[i+1]) ++i;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}   