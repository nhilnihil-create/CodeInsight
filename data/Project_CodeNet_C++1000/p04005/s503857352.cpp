#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    int cnt1 = 0;
    if(a == 1) cnt1++;
    if(b == 1) cnt1++;
    if(c == 1) cnt1++;

    if( !(a % 2) || !(b % 2) || !(c % 2)){
        cout << 0 << endl;
    }else{
        int ans = min(a*b, b*c);
        ans = min(ans, c*a);
        cout << ans << endl;
    }
}