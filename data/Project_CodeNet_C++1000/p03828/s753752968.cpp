#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int mod=1e9+7;
int a[100005];
void seive()
{
    for(int i=2;i*i<=100000;i++)
    {
        if(!a[i])
        {
            for(int j=i*i;j<=100000;j+=i)
            a[j]=i;
        }
    }
}
int32_t main()
{
  seive();

  int n;
  cin>>n;
   map<int,int> m;
   for(int i=2;i<=n;i++)
   {
       int temp=i;
       while(a[temp]!=0)
       {
            m[a[temp]]++;
            temp=temp/a[temp];
       }
       m[temp]++;
   }
   int ans=1;
   for(auto i:m)
   {
       if(i.first==1)
       continue;
       else
       {
           
           ans=(ans*(i.second+1))%mod;
       }
   }
   cout<<ans<<endl;
}