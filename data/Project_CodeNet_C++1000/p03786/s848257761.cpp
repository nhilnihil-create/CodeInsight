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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> b(n);
    b[0]=a[0];
    for(int i = 1; i < n; i++) {
        b[i]=b[i-1]+a[i];
    }

    int idx=n;
    while(idx>0) {
        idx--;
        if(b[idx-1]*2<a[idx]) break;
    }
    cout << n-idx << "\n";
    return 0;
}