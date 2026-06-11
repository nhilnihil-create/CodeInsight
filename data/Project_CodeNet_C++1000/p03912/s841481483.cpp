#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
signed main(void){
    int n,m; cin>>n>>m;
    vector <int> a(n), mo(m),dic(100005); 
    rep(i,n) {cin>>a[i]; mo[a[i]%m]++; dic[a[i]]++;}
    vector <int> need(m);
    int ans = 0;
    ans += mo[0]/2;
    mo[0] = 0;
    need[0] = INF;
    if(m%2==0) ans += mo[m/2]/2, mo[m/2] = 0;
    //cout<<m/2<<endl;
    for(int i=1;i<=m/2;i++){
        //cout<<i<<' '<<m-i<<endl;
        need[i] = need[m-i] = min(mo[i],mo[m-i]);
        ans += need[i];
    }
    if(m%2==0) need[m/2] = INF;
    /*rep(i,m){
        cout<<need[i]<<endl;
    }*/
    rep(i, 100005){
        while(dic[i]>=2){
            if(need[i%m] <= mo[i%m]-2){
                ans++;
                mo[i%m]-=2;
                dic[i]-=2;
            }else break;
        }
    }
    
    cout<<ans<<endl;
}
