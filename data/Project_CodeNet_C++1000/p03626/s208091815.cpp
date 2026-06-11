#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> v(2);
    rep(i, 2) cin >> v[i];

    string s = "";
    rep(i, n-1){
        if(v[0][i] != v[0][i+1]) s += "0";
        else {
            s += "1";
            i++;
        }
    }
    if(n == 1) s = "0";
    if(n >= 2 && v[0][n-1] != v[0][n-2]) s += "0";
    
    const ll mod = 1e9 + 7;
    ll ans;
    if(s[0] == '0') ans = 3;
    else ans = 6;
    for(int i=1; i<n; i++){
        if(s[i] == '0'){
            if(s[i-1] == '0') ans *= 2;
            else ans *= 1;
        }
        else if(s[i] == '1'){
            if(s[i-1] == '0') ans *= 2;
            else ans *= 3;
        }
        ans %= mod;
    }

    cout << ans << endl;
}