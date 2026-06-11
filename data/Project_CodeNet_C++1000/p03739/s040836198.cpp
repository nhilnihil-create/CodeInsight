#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sp=0;
    ll sn=0;
    ll cntp=0;
    ll cntn=0;
    for(ll i = 0; i < n; i++) {
        sp+=a[i];
        sn+=a[i];
        if(i%2){
            if(sp>=0){
                cntp+=(1+sp);
                sp=-1;
            }
            if(sn<=0){
                cntn+=(1-sn);
                sn=1;
            }
        }
        else{
            if(sp<=0){
                cntp+=(1-sp);
                sp=1;
            }
            if(sn>=0){
                cntn+=(1+sn);
                sn=-1;
            }
        }
    }
//    cout << cntp << " " << cntn << "\n";
    cout << min(cntp,cntn) << "\n";
    return 0;
}