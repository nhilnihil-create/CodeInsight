#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<int, int> p;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> from;
  vector<bool> check(200010, false);
  bool f = false;
  rep(i, m){
    int a, b;
    cin >> a>> b;
    if(a==1)from.push_back(b);
    if(b==n) check.at(a)=true;
  }
  int na = from.size();
  
  rep(i, na){
    int now = from.at(i);
    if(check.at(now)){
      f = true;
      break;
    }
}
  if(f) cout <<"POSSIBLE";
  else cout << "IMPOSSIBLE";
  }
