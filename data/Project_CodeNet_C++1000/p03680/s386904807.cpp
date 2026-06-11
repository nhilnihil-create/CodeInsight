#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

int main(void)
{
    ll N;
    cin >> N;

    vector<int> A(N);
    REP(i,N) {
        cin >> A[i];
    }

    ll ans = 0;
    ll now = 0;
    REP(i,N) {
        now = A[now]-1;
        ans++;
        if (now == 1) {
            break;
        }
    }

    if (now != 1) ans = -1;
    cout << ans << endl;

    return 0;
}
