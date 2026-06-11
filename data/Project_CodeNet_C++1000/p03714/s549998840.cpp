#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i,3*n) cin >> a[i];
    vector<ll> mx,mn;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll sum = 0;
    rep(i,n){
        pq.push(a[i]);
        sum += a[i];
    }
    mx.push_back(sum);
    for(int i=n;i<2*n;i++){
        if(pq.top() < a[i]){
            sum -= pq.top();
            sum += a[i];
            pq.pop();
            pq.push(a[i]);
        }
        mx.push_back(sum);
    }

    priority_queue<ll> pq1;
    sum = 0;
    rep(i,n){
        pq1.push(a[3*n-i-1]);
        sum += a[3*n-i-1];
    }
    mn.push_back(sum);
    for(int i=2*n-1;i>=n;i--){
        if(pq1.top() > a[i]){
            sum -= pq1.top();
            sum += a[i];
            pq1.pop();
            pq1.push(a[i]);
        }
        mn.push_back(sum);
    }
    reverse(mn.begin(),mn.end());

    ll ans = -LINF;
    rep(i,n+1){
        ans = max(ans,mx[i] - mn[i]);
    }
    cout << ans << endl;

    /*
    rep(i,n+1){
        cout << mx[i] << " " << mn[i] << endl;
    }
    */

    return 0;
}