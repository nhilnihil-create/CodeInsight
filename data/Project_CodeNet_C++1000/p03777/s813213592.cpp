#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    string a, b; cin >> a >> b;
    string ans;
    if(a[0]=='H'&&b[0]=='H') ans = 'H';
    else if(a[0]=='H'&&b[0]=='D') ans = 'D';
    else if(a[0]=='D'&&b[0]=='H') ans = 'D';
    else ans = 'H';
    cout << ans;
}
