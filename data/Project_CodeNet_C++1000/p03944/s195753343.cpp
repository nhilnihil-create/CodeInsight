
// 1835
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
    int W, H, N;
    cin >> W >> H >> N;
    int left = 0, right = W, bottom = 0, top = H;
 
    for(int i=0; i<N; i++) {
          int x, y, a;
        cin >> x >> y >> a;
 
        if(a == 1) {
            left = max(left, x);
        }
        else if(a == 2) {
            right = min(right, x);
        }
        else if(a == 3) {
            bottom = max(bottom, y);
        }
        else if(a == 4) {
           top = min(top, y);
        }
    }
    if(left >= right || bottom >= top) {
        cout << 0 << endl;
        return 0;
    }
    cout << (right - left) * (top - bottom ) << "\n";

    
    
    
    return 0;
}