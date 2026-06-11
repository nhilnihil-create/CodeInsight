#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i=0; i<(n); i++)
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){
    ll N; cin >> N;
    vector <ll> A(N);
    vector <ll> B(N);
    rep(i,N) cin >> A[i] >> B[i];
    
    
    ll cnt=0;
    for (ll i=N-1; i>=0; i--){
        A[i]+=cnt;
        if (A[i]%B[i]==0) continue;
        cnt+=(B[i] - (A[i]%B[i]));
    }
    cout << cnt << endl;
    
}
