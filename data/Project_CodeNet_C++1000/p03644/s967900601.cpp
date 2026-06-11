#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 
 
int32_t main()
{
    fast;
    int n; cin >> n;
    int ans = 1, hi = 0;
    Rep(i, 1, n) {
        int x = i;
        int count = 0;
    
        while (x % 2 == 0) {
            count++;
            x /= 2;
        }
    
        if(count > hi) {
            hi = count;
            ans = i;
        }
    }
    cout << ans;


    return 0;
}