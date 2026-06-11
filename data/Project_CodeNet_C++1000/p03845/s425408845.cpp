#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   int t;
   cin>>t;
   int arr[t];
   for(int i=0;i<t;i++)
    cin>>arr[i];
   long long int sum=0;
   for(int i=0;i<t;i++)
   sum=sum+arr[i];
 
   int q;
   cin>>q;
   while(q--)
   {
      int a,b;
      cin>>a>>b;
      cout<<sum+b-arr[a-1]<<endl;
      
   }
   
    return 0;
}






