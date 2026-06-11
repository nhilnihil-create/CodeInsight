#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int n;
  cin >> n;
  vector<string> maze(2);
  rep(i,2) cin >> maze.at(i);
  
  vector<ll> dp(n);
  int i;
  if(maze.at(0).at(0) == maze.at(1).at(0)) { dp.at(0) = 3; i = 1;}
  else { dp.at(0) = dp.at(1) = 6; i = 2;}
  
  while(i < n){
    if(maze.at(0).at(i) == maze.at(1).at(i)){
      if(maze.at(0).at(i-1) == maze.at(1).at(i-1)){
        dp.at(i) = (2*dp.at(i-1))%MOD;
        i++;
      }else{
        dp.at(i) = dp.at(i-1);
        i ++;
      }
    }else{
      if(maze.at(0).at(i-1) == maze.at(1).at(i-1)){
        dp.at(i+1) = (2 * dp.at(i-1))%MOD;
        i += 2;
      }else{
        dp.at(i+1) = (3 * dp.at(i-1))%MOD;
        i += 2;
      }
    }
  }
  
  cout << dp.at(n-1) << endl;  
    
  return 0;
}

