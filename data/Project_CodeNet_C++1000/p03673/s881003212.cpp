#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    vector<int> ans;
    for(int i=0;i<n;i++){
        if((n-i-1)%2==1) ans.pb(a[n-1-i]);
    }
    for(int i=0;i<n;i+=2){
        ans.pb(a[i]);
    }
    if(n%2==0){
        rep(i,n) cout << ans[i] << " ";
    }else{
        rep(i,n) cout << ans[n-1-i] << " ";
    }
}
