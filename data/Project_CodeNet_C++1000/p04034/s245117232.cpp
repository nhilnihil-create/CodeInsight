#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m;
  cin>>n>>m;
  vector<long long>a(n,1);
  vector<bool>hantei(n,0);
  hantei[0]=true;
  for(long long i=0;i<m;i++){
    long long x,y;
    cin>>x>>y;
    x--;y--;
    if(hantei[x]==1){
      a[x]--;
      a[y]++;
      hantei[y]=true;
      if(a[x]==0)hantei[x]=0;
    }else{
      a[x]--;
      a[y]++;
    }
  }
  long long  kotae=0;
  for(long long i=0;i<n;i++){
    if(hantei[i]==true)kotae++;
  }
  cout<<kotae<<endl;
  return 0;
}
    
    
  