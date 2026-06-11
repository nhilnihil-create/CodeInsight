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
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    rep(i,N){
        rep(j,M){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    ll ans = N;
    vector<ll> memo(M,1);
    rep(j,M){
        //cout << "Memo ";
        //PR(memo,M);
        vector<ll> note(M,0);
        rep(i,N){
            rep(k,M){
                if(memo[A[i][k]] == 0) continue;
                note[A[i][k]]++;
                break;
            }
        }
        //PR(note,M);
        ll Mat = 0;
        ll id = -1;
        rep(i,M){
            if(memo[i] == 0) continue;
            if(Mat < note[i]){
                Mat = note[i];
                id = i;
            }
        }
        //cout << "Mat:" << Mat << endl;
        if(id != -1){
            cmin(ans, Mat);
            memo[id] = 0;
        }
    }
    cout << ans << endl;
}