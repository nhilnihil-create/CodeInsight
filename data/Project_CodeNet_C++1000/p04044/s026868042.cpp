
// 03 02
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

vector<string> ans;
 
int32_t main()
{
    fast;
    int n, l; cin >> n >> l;
    For(i, 0, n) {
        string s; cin >> s;
        ans.pb(s);
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x;
    
    
    
    return 0;
}