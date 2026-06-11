/** これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました **/
#include<bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<y;i++)
#define repr(i,x,y) for(int i=x;i>=y;i--) 
#define mod 1000000007
using namespace std;
const int maxN=100005;
void Onigiri()
{
 int n;
 cin>>n;
 int a[3*n];
 rep(i,0,3*n)
 cin>>a[i];

 multiset<int> ms; 
 int dpl[3*n]={0},dpr[3*n]={0};
 int sum=0;
 rep(i,0,3*n)
 {
   if(ms.size()<n){
      ms.insert(a[i]);
      sum+=a[i];
      dpl[i]=sum;
   }
   else{
      ms.insert(a[i]);
      sum+=a[i];
      sum-=*ms.begin();
      ms.erase(ms.begin());
      dpl[i]=sum;
   }
 }

 multiset<int,greater<int>>ms2;
 sum=0;
 repr(i,3*n-1,0)
 {
   if(ms2.size()<n){
      ms2.insert(a[i]);
      sum+=a[i];
      dpr[i]=sum;
   }
   else{
      ms2.insert(a[i]);
      sum+=a[i];
      sum-=*ms2.begin();
      ms2.erase(ms2.begin());
      dpr[i]=sum;
   }
 }

 int ans=INT64_MIN;
 rep(i,n-1,3*n-n)
 { 
   //if(dpl[i]==-1||dpr[i+1]==-1)continue;
   //cout<<dpl[i]<<" : "<<dpr[i+1]<<endl;
   ans=max(ans,dpl[i]-dpr[i+1]);
 }
 cout<<ans;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   #ifdef Zoro
   freopen("/home/pritish/Competitive/in", "r", stdin);
   freopen("/home/pritish/Competitive/out", "w", stdout);
   #endif  
 
   int t=1; 
   //cin>>t;
 
   while(t--)
   {Onigiri();cout<<"\n";}

   cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
   return 0;
}