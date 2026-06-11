#include<bits/stdc++.h>
using namespace std;

int main(void){
  char s1[10], s2[10], s3[10];
  char ans[4] = {'\0'};
  cin >> s1 >> s2 >> s3;
  ans[0] = s1[0] - 32;
  ans[1] = s2[0] - 32;
  ans[2] = s3[0] - 32;
  cout << ans << "\n";
  return 0;
}
