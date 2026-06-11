#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(ll a,ll b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}
int main(){
  ll i,n,t[110];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> t[i];
  }
  if(n==1){
    cout << t[0] << endl;
    return 0;
  }
  ll x=lcm(t[0],t[1]);
  for(i=2;i<n;i++){
    x=lcm(x,t[i]);
  }
  cout << x << endl;
  return 0;
}