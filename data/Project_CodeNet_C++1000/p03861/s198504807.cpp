#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
   ll a,b,x,f,l,ans=0;
   cin>>a>>b>>x;
   
   f=a/x;
   l=b/x;
   ans=(l-f); 
   if(a%x==0) ans++;
   cout<<ans;
   return 0;
}
