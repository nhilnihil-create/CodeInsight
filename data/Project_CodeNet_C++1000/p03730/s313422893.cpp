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
    ll A, B,C;
    cin >> A >> B >> C;

    string ans ="NO";
    for (int i = 0; i < B; i++) {
        if (A*i % B == C) {
            ans = "YES";
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
