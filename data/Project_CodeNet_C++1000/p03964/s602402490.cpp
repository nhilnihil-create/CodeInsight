#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int n;cin >> n;
    vector<ll> t(n),a(n);
    ll A=1,B=1;
    for(int i=0;i<n;i++) cin >> t[i] >> a[i];
    for(int i=0;i<n;i++){
        A=(A+t[i]-1)/t[i];
        B=(B+a[i]-1)/a[i];
        ll mx=max(A,B);
        A=mx*t[i];
        B=mx*a[i];
    }
    cout << A+B << endl;
    return 0;
}