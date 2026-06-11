#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int H,W,N;
  cin>>H>>W>>N;
  int a,b;
  std::vector<int> v(N*9,-1);
  int x[3]={-1,0,1};
  int y[3]={-1,0,1};
  for(int i=0;i<N;i++){
    cin>>a>>b;
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(1<a+y[j]&&a+y[j]<H&&1<b+x[k]&&b+x[k]<W)v[i*9+3*j+k]=(a+y[j])*1000000000+b+x[k];
      }
    }
  }
  sort(v.begin(),v.end());
  std::vector<int> ans(10,0);
  int c=1;
  for(int i=0;i<N*9-1;i++){
    if(v[i]!=-1){
      if(v[i]==v[i+1])c++;
      else{
        ans[c]++;
        c=1;
      }
    }
  }
  if(N)ans[c]++;
  ans[0]=(H-2)*(W-2);
  for(int i=1;i<10;i++)ans[0]-=ans[i];
  for(int i=0;i<10;i++)cout<<ans[i]<<endl;
}
