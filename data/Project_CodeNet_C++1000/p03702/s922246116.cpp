#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<sstream>
#include<bitset>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back
#define ALL(x)	x.begin(),x.end()
#define fst first
#define sec second
#define PQ priority_queue
typedef long long ll;
const double eps = 1e-6;
const int maxn=1e6+10;;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const double pi=acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;} 
ll n,A,B;
ll a[maxn];
int check(ll m)
{
   ll tem=m*B;
   ll dif=A-B;
   ll sum=0;
   for(int i=n-1;i>=0;i--)
   {
     if(a[i]>tem)
     {
       if((a[i]-tem)%dif) sum+=(a[i]-tem)/dif+1;
       else sum+=(a[i]-tem)/dif;
     }
   
   }
   if(sum<=m) return 1;
   else return 0; 
}
int main()
{
   cin>>n>>A>>B;
   ll MAX=0;
  for(int i=0;i<n;++i)
    {cin>>a[i];MAX=max(a[i],MAX);}
    sort(a,a+n);
  int l,r,mid=0;
  l=1;
  r=inf;
  mid=(l+r)/2;
  while(l<r)
  {
    mid=(l+r)/2;
    if(check(mid)) r=mid;
    else l=mid+1;
  }
  //cout<<mid<<endl;
  cout<<l<<endl;
    return 0;
}