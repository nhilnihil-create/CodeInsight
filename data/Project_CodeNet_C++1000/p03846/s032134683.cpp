//Author- Vaibhav singh
//will be expert soon 
// *#####################################################################################*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define YES cout<<"YES"<<"\n";
#define NO cout<<"NO"<<"\n";
#define yes cout<<"yes"<<"\n";
#define no cout<<"no"<<"\n";
#define No cout<<"No"<<"\n";
#define Yes cout<<"Yes"<<"\n";
#define f(i,a) for(i=0;i<a;i++)
#define fo(i,a) for(i=1;i<=n;i++)
#define fa(i,a) for(auto i:a)
#define r(i,a) for(auto i=a.rbegin();i!=a.rend();i++)
#define en cout<<"\n";
#define ull unsigned long long int
#define o(x) cout<<x<<"\n";
#define o1(x) cout<<x<<" ";
#define pb push_back
#define F first
#define in insert
#define mp make_pair
#define S second
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;cin>>t;while(t-->0)
const ll Mod = 998244353;
#define mod 1000000007
#define re return 0;
// *#######################################################################################*
// *#########################################################################################*
    //      ll ans=0,b[5000005]={0},a[5000005],i,n,x=0;                
    

int main()
{
      
      fast
    ll n;cin>>n;
    ll a[n],i;
    
    f(i,n)
    {
        cin>>a[i];
    }
         
         sort(a,a+n);
         ll z=0;
         if(n%2==1)
         {
             f(i,n-1)
             {
                 if(i%2==0 && a[i+1]!=a[i]+2 || i%2==1 && a[i+1]!=a[i])
                 {
                     z=1;
                 }
             }
             if(a[0]!=0||z==1)
             {
                 o("0")
                 re
             }
             
         }
         
         else
         {
             z=0;
             f(i,n-1)
             {
                 if(i%2==1 && a[i+1]!=a[i]+2 || i%2==0 && a[i+1]!=a[i])
                 {
                     z=1;
                 }

             }
             
             if(a[0]!=1||z==1)
             {
                 o("0")
                 re
             }
             
             
         }
         
         
         
         ll sum=1;
         
         f(i,n/2)
         {
             sum*=2;
             sum=sum%mod;
         }
         
         
         
         
         o(sum%mod)
        
        
	re
}