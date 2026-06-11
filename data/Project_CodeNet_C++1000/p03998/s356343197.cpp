#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<string> s(3);
  rep(i,3)cin>>s[i];
  vector<int> vec(3);
  int x=0;
  while(1){
    if(vec[x]==s[x].size()){
      cout<<(char)(x+'A')<<endl;
      return 0;
    }
    vec[x]++;
    x=s[x][vec[x]-1]-'a';
  }
}