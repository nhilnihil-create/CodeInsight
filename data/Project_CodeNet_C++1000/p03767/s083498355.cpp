#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,sum=0;
    cin>>n;
    vector<ll> a(3*n);
    for(int i=0; i<3*n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=n; i<3*n; i++) {
        sum += a[i];
        i++;
    }
    cout<<sum<<"\n";
}