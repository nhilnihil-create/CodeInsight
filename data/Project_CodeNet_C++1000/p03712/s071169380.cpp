// 1807
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

char a[105][105];
 
int32_t main()
{
    fast;
    int h, w; cin >> h >> w;
    For(i, 0, w + 2) cout << '#';
    cout << "\n";
    For(i, 0, h) {
        cout << '#';
        For(j, 0, w) {
            cin >> a[i][j];
            cout << a[i][j];
        }
        cout << "#\n";
    }
    For(i, 0, w + 2) cout << '#';
    
    
    return 0;
}