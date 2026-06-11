#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vll t(n);
    rep(i, n) cin >> t[i];
    vll a(n);
    rep(i, n) cin >> a[i];
    ll count=1;
    rep(i,n){
        if(i==0){
            if(a[0]!=a[1]&&a[0]!=t[0]){
                cout << 0 << endl;
                return 0;
            }
        }if(i==n-1){
            if(t[n-2]!=t[n-1]&&a[n-1]!=t[n-1]){
                cout << 0 << endl;
                return 0;
            }
        }else{
            if(t[i-1]!=t[i]&&a[i]!=a[i+1]){
                if(t[i]!=a[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }else if(t[i-1]==t[i]&&a[i]==a[i+1]){
                count*=min(t[i],a[i]);
                count%=mod;
            }else if(t[i-1]==t[i]){
                if(a[i]>t[i-1]){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(t[i]>a[i+1]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cout << count << endl;
}