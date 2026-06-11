#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int x,y; cin >> x >> y;
  vector<int> g1 = {1,3,5,7,8,10,12},g2 = {4,6,9,11},g3 = {2};

  bool bool_x = false,bool_y = false;
  rep(i,g1.size()){
    if(x==g1[i]) bool_x = true;
    if(y==g1[i]) bool_y = true;
  }
  if(bool_x && bool_y){
    cout << "Yes" << endl;
    return 0;
  }

  bool_x = false;
  bool_y = false;
  rep(i,g2.size()){
    if(x==g2[i]) bool_x = true;
    if(y==g2[i]) bool_y = true;
  }
  if(bool_x && bool_y){
    cout << "Yes" << endl;
    return 0;    
  }

  bool_x = false;
  bool_y = false;
  if(x == g3[0] && y == g3[0]){
    bool_x = true;
    bool_y = true;
  }
  if(bool_x && bool_y){
    cout << "Yes" << endl;
    return 0;    
  }

  cout << "No" << endl;
  
  return 0;
}
