#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  if(x == 1 || x == 2*n-1){
    cout << "No" << endl;
    return 0;
  }
  vector<int> ans(2*n-1);
  if(x >= n){
    for(int i=0; i<2*n-1; ++i){
      ans[i] = x-n +i +1;
      if(ans[i] > 2*n-1) ans[i] -= 2*n-1;
    }
  }else{
    for(int i=0; i<2*n-1; ++i){
      ans[i] = n +x +i;
      if(ans[i] > 2*n-1) ans[i] -= 2*n-1;
    }
  }
  printf("Yes\n");
  for(int i=0; i<2*n-1; ++i){
    printf("%d\n", ans[i]);
  }
}