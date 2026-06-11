#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  char s[205];
  cin >>s;
  int n = strlen(s);
  for(int i = n-2; i; i-=2){
    if(strncmp(s, s+i/2, i/2)==0){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
