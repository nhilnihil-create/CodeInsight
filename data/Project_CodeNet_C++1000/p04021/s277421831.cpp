#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
 
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll,ll> mp;
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        mp[A[i]] = i;
    }
    sort(A.begin(), A.end());
    ll OtoE = 0;
    ll EtoO = 0;
    rep(i,N){
        if((mp[A[i]] - i) % 2 != 0){
            if(mp[A[i]]%2 == 0){
                EtoO++;
            }else{
                OtoE++;
            }
        }
    }
    cout << OtoE << endl;
}