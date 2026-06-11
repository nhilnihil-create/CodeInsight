
// 1203
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf INT_MAX
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

int a[105];
 
int32_t main()
{
    fast;
    int n, ans = inf, val; cin >> n;
    For(i, 0, n) cin >> a[i];

    sort(a, a+n);
    int l = a[0], h = a[n-1];

    Rep(j, l, h) {
        val = 0;
        For(i, 0, n) {
            val += ((a[i] - j) * (a[i] - j));
        }
        //cout << val << " ";
        ans = min(val, ans);
    }

    cout << ans;

    
    return 0;
}