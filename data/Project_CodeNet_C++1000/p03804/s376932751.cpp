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
    ll n, m; cin >> n >> m;
    vector<string> a(n), b(m);
    cin >> a >> b;
    rep(i, n){
        rep(j, n){
            //cout << i << " " << j << endl;
            bool z = true;
            if(i+m > n || j+m > n) continue;
            for(ll k = i; k < m+i; ++k){
                string x = a[k].substr(j, m), y = b[k-i];
                //cout << x << " " << y << endl;
                if(x != y) z = false;
            }
            if(z){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}