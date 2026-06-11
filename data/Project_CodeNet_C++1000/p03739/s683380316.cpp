#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<ll> A,S;
    rep(i,N) {
        int a;
        cin >> a;
        A.push_back(a);
        if (i==0) S.push_back(a);
        else S.push_back(S[i-1]+a);
    }
    ll ans1 = 0;
    ll sub = 0;
    
    rep(i,N) {
        if (i%2==0) {
            if (S[i]+sub>=0) {
                ans1 += S[i]+sub+1;
                sub -= S[i]+sub+1;
            }
        }
        else {
            if (S[i]+sub<=0) {
                ans1 -= S[i]+sub-1;
                sub -= S[i]+sub-1; 
            }
        }
    }

    ll ans2 = 0;
    sub = 0;
    rep(i,N) {
        if (i%2!=0) {
            if (S[i]+sub>=0) {
                ans2 += S[i]+sub+1;
                sub -= S[i]+sub+1;
            }
        }
        else {
            if (S[i]+sub<=0) {
                ans2 -= S[i]+sub-1;
                sub -= S[i]+sub-1; 
            }
        }
    }

    ll ans = min(ans1,ans2);
    cout << ans << endl;

}
