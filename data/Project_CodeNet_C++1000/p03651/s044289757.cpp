#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<int>;
using vv = vector<v>;

int gcd(int a, int b){
  if(a<b)
    swap(a,b);
  while(a%b){
    a %= b;
    swap(a,b);
  }
  return b;
}

int main(){
  int n,k;
  cin >> n >> k;
  v a(n);
  bool ok = false;
  int g;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i]>=k)ok = true;
    
    if(i) g = gcd(g,a[i]);
    else  g = a[0];
  }
  
  if(!ok)cout << "IMPOSSIBLE" << endl;
  else{
    if(g==1)cout << "POSSIBLE" << endl;
    else if(k%g==0)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
