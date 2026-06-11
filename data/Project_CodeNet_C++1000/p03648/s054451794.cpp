#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define modd 998244353
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define ar array
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld n,m;
lld arr[300000];
int main()
{
     ios;
     lld TESTS,q,a,s,b,l,r,c,k,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
     //memset(brr,-1,sizeof(brr));
     //cin>>TESTS;
     while(TESTS--)
     {
         cin>>k;
         rep(i,0,49)arr[i]=49+k/50;
         rep(i,0,k%50-1)arr[i]++;
         rep(i,k%50,49) arr[i]-=k%50;
         cout<<50<<"\n";
         rep(i,0,49)cout<<arr[i]<<" ";
     }
    return 0;
}
