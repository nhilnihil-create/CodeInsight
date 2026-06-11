
// 1137
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
    string s; cin >> s;
    int val = 0, x = 0;
    For(i, 0, n) {
        if(s[i] == 'I') {
            x++;
            if(x > val) val = x;
        }
        else {
            x--;
        }
    }
    cout << val;



    
    
    
    return 0;
}