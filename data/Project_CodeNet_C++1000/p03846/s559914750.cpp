#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long int power(int a,int b)
{
    if(b==0)
        return 1;
    long long int k=power(a,b/2);
    if(b%2==0)
        return ((k%M)*(k%M))%M;
    else
        return ((k%M)*(k%M)*(a%M))%M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   int n;
   cin>>n;
   map<int,int> mp;
   for(int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        mp[h]++;
    }

   if(n%2!=0)
   {
       for(int i=2;i<=n-1;i+=2)
       {
        if(mp[i]!=2)
        {
            cout<<0;
            return 0;
        }
       }   
       if(mp[0]==1)
        cout<<power(2,n/2);
       else
        cout<<0;
   }
   else
   {
       for(int i=1;i<=n-1;i+=2)
       {
        if(mp[i]!=2)
        {
            cout<<0;
            return 0;
        }
       }
       if(mp[0]==0)
       {
        cout<<power(2,n/2);
       }
       else
        cout<<0;
   }
   
    return 0;
}






