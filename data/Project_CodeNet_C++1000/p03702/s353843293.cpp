#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 1000000007
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=100001 ;
int main()
{
   fast ;
   ll n,a,b ;
   cin>>n>>a>>b ;
   vector<ll>h(n) ;
   for(ll i=0;i<n;i++)
    cin>>h[i] ;

   ll lo=0,hi=1e10 ;
   ll ans=hi ;
   while(lo<=hi)
   {
       ll mi=(lo+hi)/2 ;
       ll cnt=mi ;
       for(ll i=0;i<n;i++)
       {
           ll fr=mi*b ;
           if(fr<h[i])
           {
               ll x=(h[i]-fr)/(a-b) ;
               if((h[i]-fr)%(a-b)!=0)
                x++ ;

               if(cnt>=x)
                cnt-=x ;
               else
               {
                   cnt=-1 ;
                   break ;
               }
           }
       }
       if(cnt>=0)
       {
           ans=mi ;
           hi=mi-1 ;
       }
       else
       {
           lo=mi+1 ;

       }
   }
   cout<<ans ;
}
