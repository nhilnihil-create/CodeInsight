#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    int l=0, r=n-1;
    for(int i=0; i<n; ++i){
        if(!(i%2)){
            b[l] = a[n-i-1];
            l++;
        }
        else{
            b[r] = a[n-i-1];
            r--;
        }
    }
    for(auto aaa: b){
        cout << aaa << " ";
    }
    cout << "\n";
    return 0;
}
