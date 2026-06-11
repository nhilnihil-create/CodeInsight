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
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

//これは'a'を0に変える
//'a ~ z'を 0 ~ 26に
int ctoi(const char c){
    if('a' <= c && c <= 'z') return (c - 'a');
    else return -1;
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int H,W;cin >> H >> W;
    char C[H][W];REP(i,H) REP(j,W) cin >> C[i][j];
    int A[110] = {};
    REP(i,H) REP(j,W){
        int cnt = ctoi(C[i][j]);
        A[cnt]++;
    }
    vector<int> V,X;
    REP(i,110) if(A[i] != 0){
        V.pb(A[i]);
    }
    REP(i,V.size()){
        while(V[i] > 4){
            V.pb(4);
            V[i] -= 4;
        }
    }
    sort ALL(V);
    if(H % 2 == 0 && W % 2 == 0){
        REP(i,H/2*W/2) X.pb(4);
    }
    else if(H % 2 == 1 && W % 2 == 1){
        X.pb(1);
        REP(i,H/2) X.pb(2);
        REP(i,W/2) X.pb(2);
        int cnt = (H+1)/2*(W+1)/2 - 1 - H/2 - W/2;
        if(cnt > 0) REP(i,cnt) X.pb(4);
    }
    else{
        if(H % 2 == 1){
            REP(i,W/2) X.pb(2);
            int cnt = (H+1)/2*((W+1)/2) - W/2;
            if(cnt > 0) REP(i,cnt) X.pb(4);
        }
        else{
            REP(i,H/2) X.pb(2);
            int cnt = (H+1)/2*((W+1)/2) - H/2;
            if(cnt > 0) REP(i,cnt) X.pb(4);
        }
    }

    REP(i,X.size()){
        REP(j,V.size()){
            if(X[i] == 1){if(V[j] == 1 || V[j] == 3){
                V[j]--;break;
            }}
            else if(V[j] % 2 == 0 && V[j] - X[i] >= 0 && X[i] % 2 == 0){
                V[j] -= X[i];break;
            }
            else if(j == V.size() - 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}