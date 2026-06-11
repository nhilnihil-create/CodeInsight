#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
void Yes() {
    cout << "Yes" << endl;
}
void No() {
    cout << "No" << endl;
}
int main(void) {
    int n; cin >> n;
    if(n/10==9 || n%10==9) Yes();
    else No();
}
