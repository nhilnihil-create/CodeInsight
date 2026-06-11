#include <bits/stdc++.h>
using namespace std;

int main(){
  long long H, W;
  cin >> H >> W;
  long long ans1, ans2, ans3, ans4, ans5, ans6;
  ans1=H*((W+2)/3-W/3);
  ans2=W*((H+2)/3-H/3);
  ans3 = max({(H+2)/3*W,(H-(H+2)/3)*(W/2),(H-(H+2)/3)*((W+1)/2)})
  - min({(H+2)/3*W,(H-(H+2)/3)*(W/2),(H-(H+2)/3)*((W+1)/2)});
  ans4 = max({H/3*W,(H-H/3)*(W/2),(H-H/3)*((W+1)/2)})
  - min({H/3*W,(H-H/3)*(W/2),(H-H/3)*((W+1)/2)});
  ans5 = max({(W+2)/3*H,(W-(W+2)/3)*(H/2),(W-(W+2)/3)*((H+1)/2)})
  - min({(W+2)/3*H,(W-(W+2)/3)*(H/2),(W-(W+2)/3)*((H+1)/2)});
  ans6 = max({W/3*H,(W-W/3)*(H/2),(W-W/3)*((H+1)/2)})
  - min({W/3*H,(W-W/3)*(H/2),(W-W/3)*((H+1)/2)});

  cout << min({ans1,ans2,ans3,ans4,ans5,ans6}) << endl;
}