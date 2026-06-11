#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

//constexpr ll mod = 1000000007;
//constexpr ll INF = mod * mod;
//constexpr double pi = 3.14159265358979;

int main() {
    int n;
    string s,t;
    cin >> n >> s >> t;
    int ans = n*2;
    rep(i,n) {
        string a = s.substr(i);
        string b = t.substr(0,n-i);
        if(a == b) {
            int counter = n*2 - (n-i);
            ans = min(ans,counter);
        }
    }
    cout << ans << endl;
}