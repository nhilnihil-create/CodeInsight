#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    vector<int> vc(3);
    rep(i, 3) cin >> vc[i];
    sort(vc.begin(), vc.end());
    cout << vc[0] + vc[1];
}
