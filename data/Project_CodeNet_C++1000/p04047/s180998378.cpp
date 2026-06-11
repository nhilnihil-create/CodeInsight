#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
int main(){
    ll n; cin >> n;
    vll l(2*n);
    rep(i,2*n)cin >> l[i];
    sort(all(l));
    //rep(i,2*n)cout << l[i] << ((i < 2*n - 1)?" ":"\n");
    ll ans = 0;
    rep(i,n){
        ans += l[2*i];
        //cout << l[2*i] <<  " ";    
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}  