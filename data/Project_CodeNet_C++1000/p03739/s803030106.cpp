#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
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
    vector<ll> a(N),S(N+1);
    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        S[i+1] = a[i] + S[i];
    }
    ll prev = 1e18;
    ll cnt1 = 0;
    ll add1 = 0;
    REP(i,1,N+1){
        if((prev < 0 && (S[i]+add1) > 0) || (prev > 0 && (S[i]+add1) < 0)){
            prev = S[i]+add1;
        }else{
            if(prev > 0){
                cnt1 += abs(S[i]+add1) + 1;
                prev = -1;
                add1 -= abs(S[i]+add1) + 1;
            }else if(prev < 0){
                cnt1 += abs(S[i]+add1) + 1;
                prev = 1;
                add1 += abs(S[i]+add1) + 1;
            }
        }
    }
    prev = -1e18;
    ll cnt2 = 0;
    ll add2 = 0;
    REP(i,1,N+1){
        if((prev < 0 && S[i]+add2 > 0) || (prev > 0 && S[i]+add2 < 0)){
            prev = S[i]+add2;
        }else{
            cnt2 += abs(S[i]+add2) + 1;
            if(prev > 0){
                prev = -1;
                add2 -= abs(S[i]+add2) + 1;
            }else if(prev < 0){
                prev = 1;
                add2 += abs(S[i]+add2) + 1;
            }
        }
    }
    //cout << cnt1 << "," << cnt2 << endl;
    cout << min(cnt1, cnt2) << endl;
}
