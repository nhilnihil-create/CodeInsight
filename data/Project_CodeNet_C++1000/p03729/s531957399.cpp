#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int n,m;
  n = a.size();
  m = b.size();
  if(a[n-1] == b[0] && b[m-1] == c[0]){
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}
