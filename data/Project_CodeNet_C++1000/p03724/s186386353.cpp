#include<bits/stdc++.h>
using namespace std;

int k[100005];

int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;++i){
    int x,y;
    cin >> x >> y;
    k[x]++;
    k[y]++;
  }
  bool ok=true;
  for(int i=0;i<n;++i){
    if(k[i]%2==1) ok=false;
  }
  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
