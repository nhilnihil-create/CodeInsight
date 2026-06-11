#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
 
ll gcd(int a, int b){
  if(b == 0) return a;
  int r = a%b;
  return gcd(b,r);
}

int main(){
  int n,k;
  cin>>n>>k;
  bool ok = false;
  bool ok2 = false;
  int g = 0;
  rep(i,n){
    int a;
    cin>>a;
    if(a>k) ok = true;
    if(a==k) ok2 = true;
    
    if(ok2){
      cout << "POSSIBLE" << endl;
      return 0;
    }
    g = gcd(a,g);
  }
  if(!ok){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if(k%g == 0){
    puts("POSSIBLE");
  }else{
    puts("IMPOSSIBLE");
  }
}
