#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll d=0;
    
    string ans = "NO";
    for(int i=0; i < 256; i++){
        if(d%b==c) ans = "YES";
        d+=a;
    }
    
    cout << ans << endl;
}