#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
vector<int> vc(3);
bool ok = false;
void rec(int i, int a, int b) {
    if(i==3){
        if(a==b) ok = true;
        return;
    }
    rec(i+1, a+vc[i], b);
    rec(i+1, a, b+vc[i]);
}
int main(void) {
    rep(i, 3) cin >> vc[i];
    rec(0, 0, 0);
    if(ok) cout << "Yes";
    else cout << "No";
}
