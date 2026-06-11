#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    int a, b; cin >> a >> b;
    string ans;
    if(a==1) a=14;
    if(b==1) b=14;

    if(a==b) ans = "Draw";
    else if(a < b) ans = "Bob";
    else ans = "Alice";
    cout << ans;
}
