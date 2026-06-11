#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
ll n;
 cin>>n;
  ll num[n];
  ll sumn=0; 
  rep(i, n){
    cin>>num[i];
  sumn+=num[i];}
  
  ll dis[n];
  rep(i, n-1){
    dis[i]=num[i+1]-num[i];}
  dis[n-1]=num[0]-num[n-1];
  
  if(sumn%((n+1)*n/2)!=0){
    cout<<"NO"<<endl;
    return 0;}
  
  ll cnt=sumn/((n+1)*n/2);
  
  rep(i, n){
    if(num[i]<cnt){
      cout<<"NO"<<endl;
      return 0;}
  }
  
  ll ccnt=0;
  
  rep(i, n){
    if((cnt-dis[i])%n!=0){
      cout<<"NO"<<endl;
      return 0;}
    ccnt+=(cnt-dis[i])/n;
  }
  
  if(ccnt==cnt){
    cout<<"YES"<<endl;}
  else{
    cout<<"NO"<<endl;}
  
  return 0;

  
}
