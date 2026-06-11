#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string S;
  int index=0;
  bool flag;
  string dd[4] = {"maerd", "remaerd", "esare", "resare"};

  cin >> S;
  reverse(S.begin(), S.end());
  bool ans=true;
  for (int i = 0; i < S.size();){
    bool flag=false;
    for(int j=0;j<4;j++){
      string d = dd[j];
      if(S.substr(i,d.size()) == d){
        i+=d.size();
        flag=true;
      }
    }
    if(flag == false){
      ans=false;
      break;
    }
  }
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}