#include<bits/stdc++.h>
using namespace std;


int main(){
  int n, p;
  cin >> n >> p;
  int a[20000];
  int m = 0;
  for(int i=0; i<n;++i){
    cin >> a[i];
    if(a[i] % 2 == 1) m++;
  }
  if(m==0)cout << (p==0 ? (1ll <<n) : 0) << endl;
  else cout << (1ll << (n-1)) << endl;
}
