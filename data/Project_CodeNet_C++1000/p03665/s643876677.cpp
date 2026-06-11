#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long
#define lli long long  
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
long long ncr(long long x,long long y){
  long long z=1;
  long long k=x-y+1;
  while(k<=x){
      z*=k;
      z/=k-x+y;
      k++;
  }
  return z;

}

int main() {
   fast();
  // fact();
   long long int n,p;
   cin>>n>>p;
   long long a[n];
   long long int odd=0;
   long long int even=0;
   for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2==0){
      even++;
    }else{
      odd++;
    }
   }
   long long ans=0;
   
    long long int i=0;

    while(2*i+1<=odd){
       ans+=ncr(odd,2*i+1)*(1LL<<even);
       i++;
   }
   if(p%2==0){
    cout<<(1LL<<n)-ans<<"\n";
   }else{
    cout<<ans<<"\n";
   }
}
