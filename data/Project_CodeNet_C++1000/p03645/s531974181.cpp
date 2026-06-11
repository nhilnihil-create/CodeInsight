#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<int>> ship(n, vector<int>(0));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    ship.at(a).push_back(b);
    ship.at(b).push_back(a);
  }

  vector<int> check(n);
  rep(i,ship.at(0).size()){
    int is = ship.at(0).at(i);
    check.at(is) = 1;
  }
  
  rep(i,ship.at(n-1).size()){
    int is = ship.at(n-1).at(i);
    if(check.at(is)){cout<<"POSSIBLE"; return 0;}
  }

  cout << "IMPOSSIBLE";
}