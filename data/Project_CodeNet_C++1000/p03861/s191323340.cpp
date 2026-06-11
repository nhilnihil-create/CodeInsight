#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    ll a, b, x; scll(a), scll(b), scll(x);
    ll cnt = b/x - a/x;
    if (a % x == 0) cnt += 1;
    cout << cnt << endl;
    return 0;
}