#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),S(N+1);
    rep(i,N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    rep(i,N){
        S[i+1] = S[i] + A[i];
    }
    ll L=-1, R=N;
    while(L+1 < R){
        ll X = (L+R)/2;
        ll cur = S[X+1];
        ll compf = true;
        for(ll i=X+1;i<N;i++){
            if(cur*2 >= A[i]){
                cur += A[i];
            }else{
                compf = false;
                break;
            }
        }
        if(compf){
            R = X;
        }else{
            L = X;
        }
    }
    cout << N-R << endl;
}
