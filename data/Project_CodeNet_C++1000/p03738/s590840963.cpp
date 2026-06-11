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

vector<pair<char, int>> ans;
  
int32_t main()
{
    fast;
    string a, b; cin >> a >> b;
    if(a.size() > b.size()) {
        cout << "GREATER";
        return 0;
    }
    else if(a.size() < b.size()) {
        cout << "LESS";
        return 0;
    }
    else {
        For(i, 0, a.size()) {
            if(a[i] > b[i]) {
                cout << "GREATER";
                return 0;
            }
            else if(a[i] < b[i]) {
                cout << "LESS";
                return 0;
            }
        }
    }
    cout << "EQUAL";
    
    return 0;
}