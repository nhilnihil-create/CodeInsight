#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
  #endif  

      int n,l;
      cin>>n>>l;
      int a[n];
      for(int i=0;i<n;i++)
      		cin>>a[i];
      int ind=-1;
      for(int i=0;i<n-1;i++)
      {
      	if(a[i]+a[i+1]>=l)
      	{
      		ind=i;
      	}
      }
      if(ind==-1)
      		cout<<"Impossible";
      else
      {
      	cout<<"Possible\n";
      	for(int i=1;i<=ind;i++)
      	{
      		cout<<i<<"\n";
      	}
      	for(int i=n-1;i>=ind+2;i--)
      			cout<<i<<"\n";
      	cout<<ind+1;
      }
}
