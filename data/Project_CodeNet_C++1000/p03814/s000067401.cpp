#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
  string s;
  cin>>s;
  int begin,end;
  rep(i,s.size()){
      if(s[i]=='A'){
          begin=i;
          break;
      }
  }
  for(int i=s.size()-1;i>=0;i--){
      if(s[i]=='Z'){
          end=i;
          break;
      }
  }
  cout<<end-begin+1<<endl;
    return 0;
}
