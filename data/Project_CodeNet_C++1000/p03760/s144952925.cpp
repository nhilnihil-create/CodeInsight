#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
int main(){
  string O,E;
  cin>>O>>E;
  string ans;
  int countO=0; int countE=0;
  for(int i=1;i<=(O.size()+E.size());i++){
  if(i%2!=0){ans+=O[countO];countO++;}
  else{ans+=E[countE];countE++;}
  }
  cout<<ans<<endl;
  return 0;
}