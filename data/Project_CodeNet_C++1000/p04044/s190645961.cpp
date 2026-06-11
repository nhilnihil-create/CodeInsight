#include <bits/stdc++.h>
#define ll  long long int
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    fast;
   
  
   ll n,l;
   cin>>n>>l;
   vector<string> v;
   string s;
   for(ll i=0;i<n;i++)
   {
    cin>>s;
    v.push_back(s);

   }
   sort(v.begin(),v.end());
   for(ll i=0;i<n;i++)
    cout<<v[i];
cout<<"\n";


}

