#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main(){
   ll n,a[101010],ans[101010]={},sum=0,max=0,mn;
   
   vector<ll> v;
   cin>>n;

   rep(i,n){
      cin>>a[i];sum+=a[i];
      if(a[i]>max){
         v.pb(i);
         max=a[i];
      }
   }
   ll f=0;
   ll z[101010]={},x=0,y,q=v.size()-1,sum2=0;
   repr(i,n){
      if(q==0)break;
      if(a[i]<a[v[q]]){
         z[x]=a[i];
         x++;
      }else {
         y++;
      }
      if(v[q]==i){
         ll nx=0,ny=0;
         rep(j,x){
            if(a[v[q-1]]<z[j]){
               ans[i]+=z[j]-a[v[q-1]];
               ny++;
            }else{
              z[nx]=z[j];
              nx++; 
            }
         }
         x=nx;
         ans[i]+=(a[v[q]]-a[v[q-1]])*y;
         y+=ny;
         sum2+=ans[i];
         q--;
      }
      
      
   }
   ans[0]=sum-sum2;
   rep(i,n)cout<<ans[i]<<endl;

   
}
