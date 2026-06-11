#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<int, int> p;

int main(){
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n,0);
  rep(i, n) cin >> t.at(i);
  sort(t.begin(), t.end());
  ll ans = 0;
  int passenger = 1;
  int begin = 0, end=1;
  while(end < n){
    //cout << t.at(begin) << endl;
    if(t.at(end)-t.at(begin)<=k && passenger<c){
      passenger++;
      end++;
    }
    else{
      begin = end;
      end+=1;
      ans+=1;
      passenger = 1;
    }
    //cout << begin << endl;
  }
  ans +=1; 
  cout << ans;
  }
