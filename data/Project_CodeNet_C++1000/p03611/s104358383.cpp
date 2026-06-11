#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
  cin >> n;
  vector<int> c(100001, 0);
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    for(int j = -1; j <= 1; j++){
      if(a+j >= 0) c[a+j]++;
    }
  }
  int res = *max_element(c.begin(), c.end());
  cout << res << endl;
  return 0;
}
