#include <iostream>
using namespace std;

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
  int ans;
  string s;
  
  cin >> s;
  ans = s.length();
  for (char c='a'; c<='z'; c++){
    int left, len;
    left = -1; len = 0;
    for (int i=0; i<s.length(); i++){
      if (s[i]==c){
        len = MAX(len,i-left-1);
        left = i;
      }
    }
    len = MAX(len,s.length()-left-1);
    ans = MIN(ans, len);
  }
  cout << ans << endl;
  return 0;
}
