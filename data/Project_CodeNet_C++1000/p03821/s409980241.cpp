#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
#define MOD 1000000007
using ll = long long;
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n;
cin >> n;
vector<ll> a(n), b(n);
rep(i, n) cin >> a[i] >> b[i];
ll ans = 0;
a[n - 1] %= b[n-1];
rrep(i,n){
    if(a[i]>0){
        ll diff = b[i] - a[i];
        ans += diff;
        // rep(j,i){
        //     a[j] = (a[j] + diff) % b[j];
        // }        
    }
    if(i>0){
    a[i - 1] = (a[i - 1] + ans) % b[i - 1];
}
}
cout << ans << endl;
//system("pause");
return 0;
}