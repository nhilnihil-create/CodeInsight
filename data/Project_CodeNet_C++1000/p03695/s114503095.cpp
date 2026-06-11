#include <bits/stdc++.h>
#define COLOR 8
using namespace std;
int AtCoder1(int a, vector<bool> &colors) {
  for (int i = 0; i < COLOR; i++) {
    if (a >= i*400 && a < (i+1)*400) {
      colors[i] = true;
      return 0;
    }
  }
  return 1;
}
void AtCoder2(int a, vector<bool> &colors) {
  for (int i = 0; i < COLOR; i++) {
    if (a >= i*400 && a < (i+1)*400) {
      colors[i] = true;
    }
  }
}
int main() {
  vector<bool> colors1(COLOR), colors2(COLOR);
  int N,a,b=0;
  for (cin>>N; N; N--) {
    cin>>a;
    b+=AtCoder1(a,colors1);
    AtCoder2(a,colors2);
  }
  a=count(colors2.begin(),colors2.end(),true);
  cout<<max(a,1)<<' '<<b+count(colors1.begin(),colors1.end(),true);
}