#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  string str;
  cin >> str;
  int initLength = str.length();
  int length = str.length();
  int s = 0;
  rep(i, initLength){
    if(str[i] == 'S') s++;
    else{
      if(s>0){
        s--;
        length -= 2;
      }
    }
  }
  cout << length << endl;
  return 0;
}
      
      