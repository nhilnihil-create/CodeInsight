#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string ret = "xxx";
  ret[0] = s1[0];
  ret[1] = s2[0];
  ret[2] = s3[0];

  transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
  cout << ret << endl;
  return 0;
}
