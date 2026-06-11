#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    vector<int> vc(4);
    rep(i, 4) cin >> vc[i];
    cout << max(vc[0]*vc[1], vc[2]*vc[3]);
}
