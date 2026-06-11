
// 2324
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
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    const int dx = tx - sx, dy = ty - sy;

    cout << string(dy, 'U') << string(dx, 'R');
    cout << string(dy, 'D') << string(dx, 'L');
    cout << 'L' << string(dy+1, 'U') << string(dx+1, 'R') << 'D';
    cout << 'R' << string(dy+1, 'D') << string(dx+1, 'L') << 'U';
    cout << "\n";

    return 0;
}