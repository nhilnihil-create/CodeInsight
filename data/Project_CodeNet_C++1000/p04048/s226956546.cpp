#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

int solve(int a, int b) {
    if (a % b == 0) {
        int k = a / b;
        return b * (2 * k - 1);
    }   

    int k = a / b;
    int ans = b * 2 * k;
    ans += solve(b, a % b);

    #ifdef HOME
    cout << "solve " << a << ' ' << b << " : " << ans << endl;
    #endif

    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif    
    int a, b;
    cin >> a >> b;
    
    int t = a;
    a -= b;
    if (a < b)
        swap(a, b);
        
    cout << t + solve(a, b) << endl;
}