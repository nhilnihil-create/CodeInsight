#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  int n;
  cin >> n;
  map<int,int> a;
  rep(i,n) {
    int b;
    cin >> b;
    a[b] ++;
  }
  int count = 0;
  for(auto p:a){
    if(p.second <= 1);
    else if(p.second%2 == 0) p.second = 2;
    else p.second = 1;
    
    if(p.second > 1) count ++;
  }
  if(count%2 == 0) cout << a.size() << endl;
  else cout << a.size()-1 << endl;
  
  return 0;
}

