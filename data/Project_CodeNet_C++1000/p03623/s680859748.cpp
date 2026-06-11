#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,a,b,n,m;
  cin >> x >> a >> b;
  n=max(x,a)-min(x,a);
  m=max(x,b)-min(x,b);
  if(n<m){
    cout << "A" << endl;
  }
  else {
    cout << "B" << endl;
  }
}