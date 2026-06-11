#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
ll n,a[100005],sum,cnt1,cnt2;
int main(){
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<=n;i++){
      sum+=a[i];
      if(i%2 && sum<=0){
         cnt1+=1-sum;
         sum=1;
      }
      if(i%2==0 && sum>=0){
         cnt1+=sum+1;
         sum=-1;
      }
   }
   sum=0;
   for(int i=1;i<=n;i++){
      sum+=a[i];
      if(i%2==0 && sum<=0){
         cnt2+=1-sum;
         sum=1;
      }
      if(i%2 && sum>=0){
         cnt2+=sum+1;
         sum=-1;
      }
   }
   cout<<min(cnt1,cnt2);
   return 0;
}