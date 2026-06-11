#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(void){
  string s;
  cin >> s;
  int begin, end;
  for(int i = 0;i < s.size(); i++){
    if(s.at(i) == 'A'){
      begin = i;
      break;
    }
  }
  for(int i = s.size() - 1;i >= 0; i--){
    if(s.at(i) == 'Z'){
      end = i;
      break;
    }
  }
  cout << end - begin + 1 << endl;
  return 0;
}
