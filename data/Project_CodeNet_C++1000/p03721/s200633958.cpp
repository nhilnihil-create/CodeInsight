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

int num[100005];
 
int32_t main()
{
    fast;
    int n, k; cin >> n >> k;
    For(i, 0, n) {
        int a, b; cin >> a >> b;
        num[a] += b;
    }
    Rep(i, 1, 100005) {
        if(k <= num[i]) {
            cout << i;
            break;
        }
        k -= num[i];
    }
    
    
    return 0;
}