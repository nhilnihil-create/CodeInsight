#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int k=0;
  int s=100000;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    k+=x;
    if(x%10!=0) s=min(s,x);
  }
  if(k%10!=0) cout << k << endl;
  else if(s!=100000) cout << k-s << endl;
  else cout << 0 << endl;
}