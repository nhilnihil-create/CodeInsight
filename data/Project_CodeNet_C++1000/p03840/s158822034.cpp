#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d,e,f,g,ans;
  cin>>a>>b>>c>>d>>e>>f>>g;
  ans=a/2*2+d/2*2+e/2*2;
  if(a&&d&&e){
    long long mon=a%2+d%2+e%2;
    if(mon==3){ans+=3;}
    else if(mon==2){++ans;}
  }
  cout<<ans+b<<endl;
}
