#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, ans=1;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool flag=true;
    if(n%2==1) {
        if(a[0]!=0) {
            flag=false;
        }
        for(int i=1; i<n; i+=2) {
            if(a[i]!=i+1 || a[i+1]!=i+1) {
                flag=false;
                break;
            }
        }
        for(int i=1; i<=(n-1)/2; i++) {
            ans*=2;
            ans%=1000000007;
        }
    }
    else if(n%2==0) {
        for(int i=0; i<n; i+=2) {
            if(a[i]!=i+1 || a[i+1]!=i+1) {
                flag=false;
                break;
            }
        }
        for(int i=1; i<=n/2; i++) {
            ans*=2;
            ans%=1000000007;
        }
    }
    if(flag) cout << ans;
    else cout << 0;
}
