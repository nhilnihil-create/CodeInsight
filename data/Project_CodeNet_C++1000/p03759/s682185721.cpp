#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    int a, b, c; cin >> a >> b >> c;
    string ans;
    if(b-a == c-b) ans = "YES";
    else ans = "NO";
    cout << ans;
}
