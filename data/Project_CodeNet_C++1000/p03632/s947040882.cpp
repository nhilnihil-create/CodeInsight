#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int a,b,c,d; cin >> a >> b >> c >> d;
    int s = min(a,c);
    int g = max(b,d);
    int ans = 0;
    for(int i = s;i < g;i++){
        if(i >= a && i < b && i >= c && i < d){
            ans++;
        }
    }
    cout << ans << endl;
}

