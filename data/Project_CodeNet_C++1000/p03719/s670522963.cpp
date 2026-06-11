#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    int a, b, c; cin >> a >> b >> c;
    bool ok = false;
    if(a <= c && c <= b) ok = true;
    if(ok) cout << "Yes";
    else cout << "No";
}
