#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  int length = (s.size()+1)/2;
  rep(i,length){
    cout << s[2*i];
  }
  cout << endl;
}
//(ノ)>◡<(ヾ)ﾓﾁﾓﾁ