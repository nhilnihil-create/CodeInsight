#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  int ans;
  if(H%3==0 || W%3==0) ans=0;
  else if(H==2 && W==2) ans=1;
  else{
    int pall = min(H, W);
    int triH = max({H/3*W, (H-H/3)*(W/2), (H-H/3)*((W+1)/2)})-min({H/3*W, (H-H/3)*(W/2), (H-H/3)*((W+1)/2)});
    int triW = max({W/3*H, (W-W/3)*(H/2), (W-W/3)*((H+1)/2)})-min({W/3*H, (W-W/3)*(H/2), (W-W/3)*((H+1)/2)});
    int traH = max({(H+2)/3*W, (H-(H+2)/3)*(W/2), (H-(H+2)/3)*((W+1)/2)})-min({(H+2)/3*W, (H-(H+2)/3)*(W/2), (H-(H+2)/3)*((W+1)/2)});
    int traW = max({(W+2)/3*H, (W-(W+2)/3)*(H/2), (W-(W+2)/3)*((H+1)/2)})-min({(W+2)/3*H, (W-(W+2)/3)*(H/2), (W-(W+2)/3)*((H+1)/2)});
    ans =min({pall, triH, triW, traH, traW});
  }
  cout << ans << endl;
}