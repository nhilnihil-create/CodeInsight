#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
  int n,wl,i,j,w,v,wb;
  vector<int> vw[5];
  cin >> n >> wl;
  for (i=0;i<n;i++){
    cin >> w >> v;
    if (i==0) wb=w;
    vw[w-wb].push_back(v);
  }
  for (i=0;i<4;i++) sort(vw[i].begin(),vw[i].end(),greater<int>());
  
  int i1,i2,i3,i4,vs1=0,vs2,vs3,vs4,wl1,wl2,wl3,ans=0;
  for (i1=0;i1<=vw[3].size() && i1*(wb+3)<=wl;i1++){
    wl1=wl-i1*(wb+3);
    vs2=0;
    for (i2=0;i2<=vw[2].size() && i2*(wb+2)<=wl1;i2++){
      wl2=wl1-i2*(wb+2);
      vs3=0;
      for (i3=0;i3<=vw[1].size() && i3*(wb+1)<=wl2;i3++){
        wl3=wl2-i3*(wb+1);
        vs4=0;
        i4=0;
        while (i4<=vw[0].size() && (i4+1)*wb<=wl3){
          vs4+=vw[0][i4];
          i4++;
        }
        if (ans<vs1+vs2+vs3+vs4) ans=vs1+vs2+vs3+vs4;
        if (i3==vw[1].size()) break;
        vs3+=vw[1][i3];
      }
      if (i2==vw[2].size()) break;
      vs2+=vw[2][i2];
    }
    if (i1==vw[3].size()) break;
    vs1+=vw[3][i1];
  }
  cout << ans << endl;
  return 0;
}