#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  int n = s.size(), maxlen = 0;;
  for(int i = n-1; i > 0; i--){
    string ans = s.substr(0,i);
    int len = ans.size();
    if(len % 2 == 1){
        continue;
    }
      
    int flag = 0;
    for(int i = 0; i < len/2; i++){
      if(ans[i] != ans[len/2+i]){
        flag = 1;
        break;
      }
    }
    if(flag == 0 && len > maxlen){
      maxlen = len;
    }
    
  }//for
  
  cout << maxlen << endl;
      
}
