#include <iostream>
using namespace std;

int main(void){
  int n, ans;
  string s, t;
  
  cin >> n >> s >> t;
  for (int i=n; i>=0; i--){
    int flg=1;
    //cout << i << endl;
    for (int j=0; j<i; j++){
      //cout << s[n-i+j] << t[j] << endl;
      flg &= s[n-i+j]==t[j];
    }
    if (flg){
      ans = n+(n-i);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
