
// 1222
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
    string s; cin >> s;
    int a = 0, z = 0;
    For(i, 0, s.size()) {
        if(s[i] == 'A') {
            a = i;
            break;
        }
    }
    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == 'Z') {
            z = i;
            break;
        }
    }

    //cout << z - a + 1;
    //cout << z << " " << a << endl;
    if(z - a > 0)  cout << z-a+1;
    else cout << 0;
    
    
    
    
    return 0;
}