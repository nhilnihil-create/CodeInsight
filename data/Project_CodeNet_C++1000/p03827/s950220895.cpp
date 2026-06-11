#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int x = 0;
  int N;
  string S;
  cin >> N >> S;
  vector<int> x_vec;
  rep(i,N){
    if(S.at(i) == 'I'){
      x++;
      x_vec.push_back(x);
    }
    if(S.at(i) == 'D'){
      x--;
      x_vec.push_back(x);
    }
  }
  int max_x = 0;
	rep(i,N){
      if(x_vec[i] > max_x){
        max_x = x_vec[i];
      }
    }
  	cout << max_x << endl;
    return 0;
}