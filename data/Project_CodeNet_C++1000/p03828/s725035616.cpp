#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}
ll mpower(ll a,ll b,ll c){
  int z;
  if(b==0){
    z=1;
    z%=c;
    return z;
  }
  if(b==1){
    z=a;
    z%=c;
    return z;
  }
  else{
    return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
  }
}
bool IsPrime(int num){
  if(num<2) return false;
  else if(num==2) return true;
  else if(num%2==0) return false;
  double sqrtNum=sqrt(num);
  for(int i=3;i<=sqrtNum;i+=2){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  ll ans=1,mod=1000000007,a=0,b;
  for(int i=1;i<1001;i++){
    if(IsPrime(i)==true){
      b=n;
      while(b>=i){
        a+=b/i;
        b/=i;
      }
    }
    ans*=a+1;
    ans%=mod;
    a=0;
  }
  cout<<ans<<endl;
}