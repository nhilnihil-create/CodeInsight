#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    rep(i,n){
        cin >> a[i+1];
    }
    int k;
    if(n%2==0){
        rep(i,n/2){
            k=n-2*i;
            cout << a[k] << " ";
        }
        rep(i,n/2){
            k=2*i+1;
            cout << a[k];
            if(i<n/2-1) cout << " ";
        }
        cout << endl;
        return 0;
    }
    if(n%2==1){
        rep(i,n/2+1){
            k=n-2*i;
            cout << a[k] << " ";
        }
        rep(i,n/2){
            k=2*(i+1);
            cout << a[k];
            if(i<n/2-1) cout << " ";
        }
        cout << endl;
        return 0;
    }
}