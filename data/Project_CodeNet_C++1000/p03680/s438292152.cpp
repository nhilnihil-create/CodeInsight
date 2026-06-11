#include <iostream>

using namespace std;

int main()
{
  int a,s,ans;
  cin >> a;
  int b[a];
  ans = -1;
  for(int i = 0;i<a+1;i++){
    cin >> b[i];
    b[i]--;
  }
  s = 0;
  for(int i=0;i<a;i++){
    if(b[s]==1){
      ans = i+1;
      break;
    }
    else s = b[s];
  }
  cout << ans << endl;
}