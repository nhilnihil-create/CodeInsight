#include <bits/stdc++.h>
#include <queue>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  ll a,b,c;
  cin>> a>>b>>c;
  ll ans=0;
  if(a%2!=0 && (b%2!=0 && c%2!=0)){
    ans=min(a*b,min(a*c , b*c));
  }
  cout<<ans<<endl;
  

  return 0;
}
