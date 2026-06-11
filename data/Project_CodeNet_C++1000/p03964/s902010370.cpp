#include<bits/stdc++.h>
using namespace std;
long long ceil(long long x,long long y){
  if(x%y) return x/y+1;
  else return x/y;
}
int main(){
  cin.tie(0);ios::sync_with_stdio(0);
  long long n,t,a,x = 1,y = 1,h;cin >> n;
  while(cin >> t >> a){
    h = max(ceil(x,t),ceil(y,a));
    x = t*h;y = a*h;
  }
  cout << x+y << "\n";
}