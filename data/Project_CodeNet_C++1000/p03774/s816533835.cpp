#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e2;

void solve(){
    int n, m; cin>>n>>m;
    ll a[n+1], b[n+1], c[m+1], d[m+1];

    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];

    for (int i=1; i<=m; i++)
        cin>>c[i]>>d[i];

    for (int i=1; i<=n; i++){
        ll x1 = a[i]; ll y1 = b[i];

        ll mini = LONG_MAX;
        ll point = 1;
        for (int j=1; j<=m; j++){
            ll x2 = c[j];  ll y2 = d[j];

            ll x = abs(x1-x2) + abs(y1-y2);

            if(x<mini){
                mini = x; point = j;
            }
        }

        cout<<point<<endl;
    }
}

int main(){
    solve();
    Bye;
}