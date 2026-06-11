#include <bits/stdc++.h>
using namespace std;

int main() {
  long hh,ww,h,w,a=0;
  cin >> hh >> ww >> h >> w;
  vector<vector<long>> ans(hh,vector<long>(ww));
  for(long i=0;i<hh;i++) {
    for(long j=0;j<ww;j++) {
      if(i%h+j%w==0) ans[i][j]=999999999,a+=999999999;
      else if((i+1)%h+(j+1)%w==0) ans[i][j]=-1000000000,a-=1000000000;
    }
  }
  if(a>0&&h*w>1) {
    cout << "Yes" << endl;
    for(long i=0;i<hh;i++) {
      for(long j=0;j<ww;j++) cout << ans[i][j] << " ";
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}