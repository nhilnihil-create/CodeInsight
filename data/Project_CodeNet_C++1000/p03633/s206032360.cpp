#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
ll gcd(ll a, ll b)//最大公約数
{
   if (b == 0)
   {
       return a;
   }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) //最小公倍数
{
    return (a/gcd(a, b))*b;
}
int main() {
    int N;
    cin >> N;
    vector<ll>T(N);
    rep(i, 0, N){
        cin >> T[i];
    }
    ll ans = 0;
    rep(i, 0, N-1){
        T[i+1] = lcm(T[i], T[i+1]);
    }
    rep(i, 0, N){
        if(ans < T[i]){
            ans = T[i];
        }
    }
    cout << ans << endl;
    return 0;
}