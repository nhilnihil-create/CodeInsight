#include <bits/stdc++.h>
using namespace std;
int main(){
  int w,a,b;
  cin >> w >> a >> b;
  if((a <= b && b <= a+w)||(a<= b+w && b+w <= a+w)){
    cout << 0 << endl;
  }
  else {
    int x=abs(b-w-a);
    int y=abs(a-b-w);
    int answer = min(x,y);
    cout << answer  <<endl;}
}