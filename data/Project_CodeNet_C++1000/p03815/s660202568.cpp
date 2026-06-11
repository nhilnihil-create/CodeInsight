#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define INF 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;

int main(){
    ll ans=0;
    ll x;
    cin >> x;
    
    if(x <= 6)
        ans = 1;
    else if(x <= 11)
        ans = 2;
    else{
        ans = (x-1)/11*2 + (((x-1)%11 <= 5) ? 1 : 2);
    }
    
    cout << ans;
    //printf("%.15lf",ans);
    cout << "\n";
    return 0;
}
