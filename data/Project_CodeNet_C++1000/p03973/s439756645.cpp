#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int n, a, c = 1;
long long ans;

int main(){
    cin >> n;
    rep(i,n){
        cin >> a;
        if(!i) ans += a - c++;
        else if(a == c) c++;
        else ans += (a-1) / c;
    }
    cout << ans << '\n';
}