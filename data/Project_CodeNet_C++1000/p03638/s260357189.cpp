#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = (m); i < (n); i++)
 
int main() {
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  vector<int> inputs(N);
  rep(i,0,N) cin >> inputs[i];
  vector<int> vec(W);
  bool is_odd = false;
  int pos_h = 0, pos_w = 0;
  rep(i,0,N){
  	rep(j,0,inputs[i]){
      if (!is_odd){
        vec[pos_w] = i+1;
        pos_w++;
        if(pos_w == W){
          is_odd = true;
          pos_w--;
          for(int v:vec)
            cout << v << " ";
          cout << endl;
        }
      }
      else{
        vec[pos_w] = i+1;
        pos_w--;
        if(pos_w == -1){
          is_odd = false;
          pos_w++;
          for(int v:vec)
            cout << v << " ";
          cout << endl;
        }
      }
    }
  }
}