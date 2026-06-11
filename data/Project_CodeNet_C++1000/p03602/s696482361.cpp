#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef vector<int> vi;

int n;
int A[300][300];

void solve(){
    cin>>n;
    REP(i,n)
        REP(j,n)
            cin>>A[i][j];
    long long ans = 0;
    REP(i,n){
        REP(j,i){
            bool ok = true;
            REP(k,n){
                if(k==i || k == j) continue;
                if(A[i][k] + A[k][j] < A[i][j]){
                    cout<<"-1\n";
                    return;
                }
                if(A[i][k] + A[k][j] == A[i][j])
                    ok = false;
            }
            if(ok)
                ans += A[i][j];
        }
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    solve();
    return 0;
}
