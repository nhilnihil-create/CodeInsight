#include<bits/stdc++.h>
using namespace std;
#define itn int
#define int long long
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
int x,a,b;
  cin>>x>>a>>b;
  if(abs(x-a)<abs(x-b)) cout<<"A\n";
  else cout<<"B\n";
}