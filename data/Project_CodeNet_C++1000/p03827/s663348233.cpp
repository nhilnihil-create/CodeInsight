#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int n,x=0,ans=0;
    string s;
    cin>>n>>s;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='I') x++; else x--;
        ans=max(ans,x);
    }
    cout<<ans;
    
	

   return 0;
}
