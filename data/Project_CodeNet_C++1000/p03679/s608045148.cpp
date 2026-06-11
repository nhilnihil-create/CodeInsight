#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    int x, a, b; cin >> x >> a >> b;
    int c = b - a;
    if(c <= 0) cout << "delicious";
    else if(c > x) cout << "dangerous";
    else cout << "safe";
}
