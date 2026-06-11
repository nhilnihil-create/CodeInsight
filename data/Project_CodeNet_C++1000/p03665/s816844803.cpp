#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n,p;
    cin >> n >> p;
    vector<int> a(n);
    int od=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]%2) od++;
    }
    int ev=n-od;

    ll ch[od+1];
    ch[0]=1;
    for(ll i = 1; i <= od; i++) {
        ch[i]=ch[i-1]*(od-i+1)/i;
    }
    for(ll i = 0; i <= od; i++) cerr << od << " C " << i << " : " << ch[i] << "\n";
    ll ans=0;
    for(int i = 0; i <= od; i+=2) {
        ans+=ch[i];
    }
    ans*=pow(2,ev);
    if(p==1) ans=pow(2,n)-ans;
    cout << ans << "\n";
    return 0;
}