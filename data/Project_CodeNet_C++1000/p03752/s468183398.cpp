#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans = 1e17;
    for(int bit=0;bit<(1<<n);bit++){
        int cnt = 0;
        int now = 0;
        ll cost = 0;
        for(int i=0;i<n;i++){
            if(a[i] > now){
                cnt++;
                now = a[i];
            }
            else if(bit & (1<<i)){
                now++;
                cost += now - a[i];
                cnt++;
            }
        }
        if(cnt >= k)chmin(ans,cost);
    }
    cout << ans << endl;
}