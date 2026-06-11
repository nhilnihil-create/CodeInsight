#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    int d = a%b;
    if(d==c) { cout << "YES" << endl; return 0;}
    int i = 2;
    bool ok = false;
    while(1){
        int e = (a*i)%b;
        if(e==c) {ok = true; break;}
        if(e==d) break;
        ++i;
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}