#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
#define int long long
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
signed main(void){
    int n; cin>>n;
    vector <int> a(3*n); 
    rep(i,3*n) cin>>a[i];
    vector <int> d(3*n+10); 
    vector <int> rd(3*n+10); 
    priority_queue <int, vector <int>, greater<int>> q;
    d[0] = 0;
    rep(i, 3*n){
        if(i<n){
            d[i+1] = d[i] + a[i];
            q.push(a[i]);
        }else{
            int tmp = q.top();
            q.pop();
            if(tmp < a[i]){
                d[i+1] = d[i] + a[i] - tmp;
                q.push(a[i]);
            }else{
                d[i+1] = d[i];
                q.push(tmp);
            }
        }
        //cout<<d[i+1]<<endl;
    }
    rd[3*n-1] = 0;
    priority_queue <int> lq;
    for(int i=3*n-1; i>0;i--){
        if(i>= 3*n-n){
            rd[i-1] = rd[i] + a[i];
            lq.push(a[i]);
        }else{
            int tmp = lq.top();
            lq.pop();
            if(tmp > a[i]){
                rd[i-1] = rd[i] + a[i] - tmp;
                lq.push(a[i]);
            }else{
                rd[i-1] = rd[i];
                lq.push(tmp);
            }
        }
        //cout<<lq.size()<<endl;
        //cout<<rd[i-1]<<endl;
    }
    int ans = -INF;
    for(int i = n;i<=2*n; i++){
        //cout<<d[i]<<' '<<rd[i]<<endl;
        ans = max(ans, d[i] - rd[i-1]);
    }
    cout<<ans<<endl;
}
