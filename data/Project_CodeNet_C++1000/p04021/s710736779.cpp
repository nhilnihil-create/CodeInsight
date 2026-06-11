#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define fi first
#define se second
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    vector<int> A(N),E;
    REP(i,N){
        cin >> A[i];
        if(i % 2 == 0) E.pb(A[i]);
    }
    sort ALL(A);sort ALL(E);
    int Ei = 0,cnt = 0;
    REP(i,N){
        if(A[i] == E[Ei]){
            Ei++;
            if(i % 2 == 1) cnt++;
        }
    }
    cout << cnt << endl;
}