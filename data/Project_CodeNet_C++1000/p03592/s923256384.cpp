#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k,flag=0;
  cin >> n >> m >> k;
  if(n)
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(k==i*m+j*n-i*j*2) flag = 1;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
