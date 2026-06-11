#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
constexpr int mo2 = 998244353;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(auto &a : v) cin>>a;
    ll ret = 1ll*accumulate(v.begin(),v.end(),0ll);
    for(int i=1;i<n;++i){
        int tmp = v[n-1];
        for(int j=n-1;j>0;j--){
            v[j] = min(v[j-1],v[j]);
        }
        v[0] = min(v[0],tmp);
        ret = min(ret,1ll*accumulate(v.begin(),v.end(),0ll)+1ll*i*x);
    }
    cout << ret << endl;
    return 0;
}

