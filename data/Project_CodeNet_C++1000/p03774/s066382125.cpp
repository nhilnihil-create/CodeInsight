#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> point(n);
  vector<pair<int,int>> cpoint(m);
  rep(i,n){
    int x,y;
    cin >> x >> y;
    point[i]={x,y};
  }
  rep(i,m){
    int x,y;
    cin >> x >> y;
    cpoint[i]={x,y};
  }
  rep(i,n){
    int dis = 1 << 30;
    int res = -1;
    rep(j,m){
      if (abs(cpoint[j].first-point[i].first) + abs(cpoint[j].second-point[i].second) < dis){
        dis = abs(cpoint[j].first-point[i].first) + abs(cpoint[j].second-point[i].second);
        //cout << dis << endl;
        res = j+1;
      }
    }
    cout << res << endl;
  }
  return 0;
}
