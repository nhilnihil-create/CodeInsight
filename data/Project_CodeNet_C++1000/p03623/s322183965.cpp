#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,a,b;cin>>x>>a>>b;
  int ans = min(abs(x-a),abs(x-b));
  if(ans == abs(x-a)) cout<<"A"<<endl;
  else cout<<"B"<<endl;
}
