#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(b-a == c-b){
    puts("YES");
  }
  else puts("NO");
  return 0;
}
