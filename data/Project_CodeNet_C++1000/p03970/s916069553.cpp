#include <iostream>

using namespace std;

int main(void)
{
  string S, T="CODEFESTIVAL2016";
  int i, ans=0;
  
  cin >> S;
  
  for(i=0; i<16; i++){
    if(S[i] != T[i]){
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}