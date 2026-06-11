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
lld brr[300000];
lld fin[300000];
lld getSum(lld BITree[], lld index)
{
    lld sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(lld BITree[], lld n, lld index, lld val)
{
    index = index + 1;
    while (index <= n){
    BITree[index] += val;
    index += index & (-index);
    }
}
int main()
{
     ios;
     lld TESTS,q,a,s,b,r,l,k,c,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
  // cin>>TESTS;
     while(TESTS--)
     {
         cin>>n>>k;
         rep(i,1,n)cin>>arr[i];
         brr[0]=0;
         rep(i,1,n){
            brr[i]=brr[i-1];
            brr[i]+=arr[i]-k;
         }
         sort(brr,brr+n+1);
         lld sum=0;
         lld ans=0;
         lld ind=lower_bound(brr,brr+n+1,sum)-brr;
         updateBIT(fin,n+1,ind,1);
         rep(i,1,n){
            sum+=arr[i]-k;
            ind=lower_bound(brr,brr+n+1,sum)-brr;
            ans+=getSum(fin,ind);
            updateBIT(fin,n+1,ind,1);
         }
         cout<<ans;
     }
    return 0;
}
