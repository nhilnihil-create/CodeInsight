#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string x = string() + s1.at(0);
  //string str(1, x);
  char y = s2.at(0);
  char z = s3.at(0);
  cout << x + y + z << endl;
}
