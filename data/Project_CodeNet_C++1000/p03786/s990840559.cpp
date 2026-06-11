#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    sort(v.begin(), v.end());
    vector<ll> sum(n);
    sum[0] = v[0];
    rep(i, n-1){
        sum[i+1] = sum[i] + v[i+1];
    }
    int ans = 1;
    for(int i = n-2;i>=0;i--){
        if(sum[i]*2>=v[i+1]) ans ++;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}