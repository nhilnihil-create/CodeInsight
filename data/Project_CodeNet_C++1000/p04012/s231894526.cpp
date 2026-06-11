
// 1230
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

int a[27];
 
int32_t main()
{
    fast;
    string w; cin >> w;
    int flag = 0;
    if(w.size() % 2 == 1) cout << "No";
    else {
        For(i, 0, w.size()) {
            a[w[i] - 'a']++;
        }
        For(i, 0, 27) {
            if(a[i] % 2 == 0) flag = 1;
            else {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "Yes" : "No");

    }
    
    
    
    return 0;
}