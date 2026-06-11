#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    ll n,c,k;cin>>n>>c>>k;
    vector<ll> t(n);
    rep(i,n)cin>>t[i];
    
    sort(t.begin(), t.end());
    
    queue<ll> q;
    rep(i,n)q.push(t[i]);
    int ans = 0;
    while(q.size()){
        ll dep = q.front() + k;
        ans++;
        ll count = 0;
        while(q.size() && count<c && q.front()<=dep ){
            q.pop();
            count++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}