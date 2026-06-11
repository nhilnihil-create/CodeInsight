#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
typedef long long ll;

int main(){

  int n,k;
  cin >> n >> k;
  ll height[15],maxHeightPre[15], tmp_height;
  ll min_cost, tmp_cost;
  maxHeightPre[0] = 0;
  rep(i,n){
    cin >> height[i];
    if(i){
      maxHeightPre[i] = max(maxHeightPre[i-1],height[i-1]);
    } 
  }

  rep(i, 1<<n-1){
    bitset<16> bit(i);
    if(bit.count() != k-1) continue;
    tmp_cost =0;
    tmp_height =0;
    rep(j,n-1){
      if(bit[j]){
        tmp_height = max(maxHeightPre[j+1],tmp_height);
        if(height[j+1] <= tmp_height){
          tmp_height++;
          tmp_cost += tmp_height  -  height[j+1]; 
        }
      }
    }
    min_cost = min(min_cost, tmp_cost);
  }

  cout << min_cost << endl;
  return 0;
}