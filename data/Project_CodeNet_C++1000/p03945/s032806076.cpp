#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back


using namespace std;

const int maxm = 1000000000 + 7;

double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}


//----------->CODE BEGINS --------------->



int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

   
   string s;
   cin>>s;

   ll ans = 0;

   for(int i=1; i<s.length();i++)
   {
    if(s[i] != s[i-1])
    {
      ans++;
    }
   }

  
  cout<<ans<<endl;

  
  
}
 