#include<bits/stdc++.h>
#define ll long long
#define MOD 1
using namespace std;
ll n,x,ans,r;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int a[100005];
void print(int *a){
 for(int i=1;i<n;i++){
  a[i]=a[i-1]+a[i-2];
  a[i]=max(a[i],a[i+1]);
 }
 for(int i=1;i<=n;i++){a[i]++;return;}
 if(a[0]==a[1])cout<<"T";
}
void MaIn(){
 fill(a,a+100005,-1);
 a[0]=1;
 print(a);
 cin>>n>>x;
 if(gcd(n,x)==1)cout<<3*(n-1)<<endl;
 else{
  for(int i=1;i<=n;i++)
   ans=(((ans+x%MOD)+i*i%MOD)%MOD-1+MOD)%MOD;
  for(int j=1;j<=n;j++){
   ans+=j;
  }
  print(a);
 }
 cout<<ans<<endl;
 return;
}
ll solve(ll b,ll a){
 if(!b)return 0;
 ll ans=b*(a/b)+(a/b)*b;
 if(!(a%b))return ans-b;
 return ans+solve(a%b,b);
 r=b+a;
}
int main(){
 cin>>n>>x,ans=n+solve(min(x,n-x),max(x,n-x));
 cout<<ans+r<<endl;
 return 0;
}