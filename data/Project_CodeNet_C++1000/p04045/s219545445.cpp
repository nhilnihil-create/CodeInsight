
// 0308
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

bool dislike[10];

bool ok(int n) {
    while(n) {
        if(dislike[n % 10]) return false;
        n /= 10;
    } 
    return true;
}
 
int32_t main()
{
    fast;
    int n, k; cin >> n >> k;
    For(i, 0, k) {
        int d; cin >> d;
        dislike[d] = true;
    }

    for(int i = n; ; ++i) {
        if(ok(i)) {
            cout << i << "\n";
            break;
        }
    }


    return 0;
}