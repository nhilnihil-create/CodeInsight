
// 2121
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

int t[100005];
 
int32_t main()
{
    fast;
    int n; cin >> n;
    For(i, 0, n) {
        cin >> t[i];
        //x[i] = t[i];
    }
    int m; cin >> m;
    For(i, 0, m) {
        int p, val, sum = 0; cin >> p >> val;
        For(i, 0, n) {
            sum += t[i];
            if(i == p-1) sum += (val - t[i]);
        }
        cout << sum << "\n";
        

    }

    
    
    
    return 0;
}