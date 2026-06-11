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

char a[105][105], o[205][105];
 
int32_t main()
{
    fast;
    int h, w; cin >> h >> w;
    Rep(i, 1, h)  {
        Rep(j, 1, w) {
            cin >> a[i][j];
            //o[i][j] = a[i][j];
        }
    }

    Rep(i, 1, 2*h) {
        Rep(j, 1, w) {
            o[i][j] = a[(i+1) / 2][j];
        }
    }

    Rep(i, 1, 2*h) {
        Rep(j, 1, w) {
            cout << o[i][j];
        }
        cout << "\n";
    }



    
    
    
    return 0;
}