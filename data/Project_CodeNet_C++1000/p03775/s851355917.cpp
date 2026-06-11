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

int countDigits(int n) {
    string val = to_string(n);
    return val.size();
}
 
int32_t main()
{
    fast;
    int n, ans, val; cin >> n;
    ans = countDigits(n);
    Rep(i, 1, sqrt(n) + 1) {
        if(n % i == 0) {
            val = max(i, n / i);
            ans = min(ans, countDigits(val));
        }
        
    }
    cout << ans;
    
    
    
    
    return 0;
}