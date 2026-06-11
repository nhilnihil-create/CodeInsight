#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int n, sum = 0, ans = 0; sc(n);
    vector<int> a(n);
    rep(i, 0, n) sc(a[i]);
    rep(i, 0, n) sum += a[i];
    if (sum % n <= n/2) sum /= n;
    else sum = sum / n + 1;
    rep(i, 0, n) ans += (a[i]-sum) * (a[i]-sum);
    cout << ans << endl;
    return 0;
}