#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  bool ans=0;
  for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++){
      int cnt=i*n+j*m-i*j*2;
      if(cnt==k) ans=1; 
    }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

