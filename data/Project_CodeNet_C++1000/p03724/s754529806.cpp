#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n , m ; cin >> n >> m;
    vector<bool> chk(n,false);
    rep(i,m){
        ll a,b ; cin >> a >> b;
        a--; b--;
        chk.at(a) = !chk.at(a);
        chk.at(b) = !chk.at(b);        
    }
    bool flag = true;
    rep(i,n){
        if(chk.at(i)) flag = false;        
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
