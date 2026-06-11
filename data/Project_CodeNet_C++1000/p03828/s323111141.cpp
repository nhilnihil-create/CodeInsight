#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back
bool prime(int m){
  if(m==1) return 0;
  for(int i=2;i<m;i++){
    if(m%i==0) return 0;
  }
  return 1;
}
void solve(){
   vector<int>v(1001,0);
   int n; cin>>n;
   for(int i=2;i<=n;i++){
      int k=i;
      for(int j=2;j<=k;j++){
          if(k%j==0 && prime(j)){
            int l=k;
            while(l%j==0 && l>0){
              v[j]++;
              l=l/j;
            }
           

          }
      }

   }
   ll prod=1;
   ll mod=1000000007;
   
   for(int i: v) {
    if(i!=0)
    prod=((prod%mod)*(i+1)%mod)%mod;
   }
   cout<<prod<<endl;
}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

int t=1 ;  while(t--)
 solve();

return 0;
}
