#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a%2==0 || b%2==0 || c%2==0){
    cout << 0 << endl;
    return 0;
  }
  int z=max(a,b);
  ll x=min(a,b);
  ll y=min(z,c);

  cout << x*y << endl;
}