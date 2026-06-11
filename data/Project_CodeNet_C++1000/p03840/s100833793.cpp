#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll ai,ao,at,aj,al,as,az;cin>>ai>>ao>>at>>aj>>al>>as>>az;
  ll ans=(ai/2)*2+ao+(aj/2)*2+(al/2)*2;
  if(ai%2==1&&aj%2==1&&al%2==1)ans+=3;
  else{
    if(ai>0&&aj>0&&al>0){
      ll c=0;
      if(ai%2==0)c++;
      if(aj%2==0)c++;
      if(al%2==0)c++;
      if(c==1)ans++;
    }
  }
  cout<<ans<<endl;
}