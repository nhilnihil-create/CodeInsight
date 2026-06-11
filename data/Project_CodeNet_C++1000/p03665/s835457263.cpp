#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {
    ll n,p; cin >> n >> p;
    bool flag = true;
    ll tmp;
    rep(i,n) {
        cin >> tmp;
        if(tmp%2 == 1) flag = false;
    }
    if(flag && p == 0)printf("%lld",(ll)pow(2,n));
    else if(flag && p == 1)cout << 0;
    else printf("%lld",(ll)pow(2,n-1));

    return 0;
}









