#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    ll N, M;    cin >> N >> M;
    ll mod2 = 1000000007;
    ll ans = 1;
    if(abs(N-M) > 1)    ans = 0;
    else{
        for(ll i=min(N,M); i>0; i--)    ans = ans*i%mod2;
      	ans = ans*ans%mod2;
        if(N != M)  ans = ans*max(N,M)%mod2;
        else   ans = ans*2%mod2;
    }
    cout << ans;
    return 0;
}