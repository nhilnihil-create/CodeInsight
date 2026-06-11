#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,n,c = 0;
  cin >> h >> w >> n;
  vector<int>a(n);
  vector<int>str(h*w);
  for(int i = 0;i < n;i++) cin >> a[i];
  for(int i = 0;i < n;i++){
    for(int j = 0;j < a[i];j++){
      str[c] = i+1;
      c++;
    }
  }
  for(int i = 0;i < h;i++){
    vector<int>ans(w);
    for(int j=0;j < w;j++){
      ans[j] = str[w*i+j];
    }
    if(i%2 == 1) reverse(ans.begin(),ans.end());
    for(int j = 0;j < w;j++){
      cout << ans[j];
      if(j != w-1) cout << " ";
      else cout << "" << endl;
    }
  }
}