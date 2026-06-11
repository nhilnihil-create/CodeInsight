#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
    int n;
    cin>>n;
    ll ans=0;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    bool down=false,up=false;
    for (int i=0; i<n-1; i++) {
        if (a[i]<a[i+1]&&!down&&!up) up=true;
        else if(a[i]>a[i+1]&&!down&&!up) down=true;
        else if (a[i]<a[i+1]&&down) {
            down=false;
            ans++;
        }
        else if(a[i]>a[i+1]&&up) {
            up=false;
            ans++;
        }
    }
    cout<<ans+1<<endl;
}
