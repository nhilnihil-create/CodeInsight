#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i,N){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll sum=0;
    rep(i,A){
        sum+=v[i];
    }
    double ave=(double)sum/A;
    cout << fixed << setprecision(6);
    cout << ave << endl;
    ll count=0,s=-1;
    rep(i,N){
        if (v[i]==v[A-1]){
            count++;
            if (s==-1){
                s=i;
            }
        }
    }
    ll ans=0,c=1;
    if (v[A-1]!=ave){
        ans=1;
        for (int i=1;i<=A-s;i++){
            ans*=count-i+1;
            ans/=i;
        }
    }
    else {
        for (int i=1;i<=min(count,B);i++){
            c*=count-i+1;
            c/=i;
            if (i>=A){
                ans+=c;
            }
        }
    }
    cout << ans << endl;
}