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

int a[26];
 
int32_t main()
{
    fast;
    int f = 0;
    string s; cin >> s;
    For(i, 0, s.size()) ++a[s[i] - 'a'];
    for(auto x : a) if(x > 1) f = 1;
    cout << (f == 1 ? "no" : "yes");


    
    
    
    return 0;
}