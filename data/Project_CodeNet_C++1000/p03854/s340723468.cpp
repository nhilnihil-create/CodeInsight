// 0028
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

vi idx;
 
int32_t main()
{
    fast;
    string s; cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    for(int i = 0; i < n;) {
        if(s.substr(i,5) == "maerd"){
			i += 5;
		}
		else if(s.substr(i,5) == "esare"){
			i += 5;
		}
		else if(s.substr(i,6) == "resare"){
			i += 6;
		}
		
		else if(s.substr(i,7) == "remaerd"){
			i += 7;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
    }
    cout << "YES" << "\n";
    
    
    
    return 0;
}