#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    ll start = a / x, end = b / x, ans = end - start + 1;
    if(a%x != 0) ans--;
    cout << ans << endl;
    
    return 0;
}