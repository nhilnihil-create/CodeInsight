#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<int> vc(3);
    rep(i, n) {
        int a; cin >> a;
        if(a%4==0) vc[2]++;
        else if(a%2==0) vc[1]++;
        else vc[0]++;
    }
    if(vc[1]==0&&vc[0]-vc[2]<=1) cout << "Yes";
    else {
        if(vc[2] >= vc[0]) cout << "Yes";
        else cout << "No";
    }puts("");
}
