#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
  bool bo=false;
  int a,b,c;
  cin >>a>>b>>c;
  rep(i,b)
    if((i*a)%b==c)bo=true;
  if(bo)cout <<"YES"<<endl;
  else cout << "NO" << endl;
}