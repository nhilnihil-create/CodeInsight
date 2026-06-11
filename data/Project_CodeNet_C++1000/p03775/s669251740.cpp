#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}

int main() {
   fast();
  long long n;
  cin>>n;
  long long l=n;
  int ans=0;
  while(l){
    l=l/10;
    ans++;
  }
  for(long long i=2;i<=sqrt(n);i++){
    if(n%i==0){
      long long c=i;
      long long d=n/i;
      int f=0;
      int g=0;
      while(c){
        c=c/10;
        f++;
      }
      while(d){
        d=d/10;
        g++;
      }
      ans=min(ans,max(f,g));
    }
  }
  cout<<ans<<"\n";



}
