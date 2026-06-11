#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll a,b,c,d,e,f,g;
  cin>>a>>b>>c>>d>>e>>f>>g;
  ll ans=a/2*2+b+d/2*2+e/2*2;
  if(a>0&&d>0&&e>0){
    ans=max(ans,(a-1)/2*2+(d-1)/2*2+(e-1)/2*2+3+b);
  }
  cout<<ans<<endl;
}