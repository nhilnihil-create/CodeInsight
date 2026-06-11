#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int a, b, c, d; cin>> a >> b >> c >> d;
    if(a > c) swap(a, c), swap(b, d);
    cout << max(0, min(d-c, b-c));
}
