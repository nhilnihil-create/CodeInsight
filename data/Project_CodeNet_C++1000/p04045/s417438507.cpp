#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n, k;
int d[10];
void solve(){
    cin >> n >> k;
    for(int i=0;i<k;++i) {
        int  t;
        cin >> t;
        d[t] = 1;
    }
    bool fl = 1;
    auto ok = [&](int x) {
        while(x) {
            if(d[x%10])
                return 0;
            x/=10;
        }
        return 1;
    };
    while(fl) {
        if(ok(n))
            fl = 0;
        else 
            n ++;
    }
    cout << n << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

