#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)


int main() {
    int H,W;cin >> H >> W;
    int N;cin >> N;
    vector<int> A(N);
    for (int i = 0;i < N;i++){
      cin >> A.at(i);
    }

    vector<vector<int>> C(H,vector<int>(W));
    int ni = 0;
    for (int i = 0;i < H;i++){
      for (int j = 0;j < W;j++){
        if (A.at(ni) > 0){
          A.at(ni)-=1;
          C.at(i).at(j) = ni+1;
        }else{
          ni+=1;
          A.at(ni)-=1;
          C.at(i).at(j) = ni+1;
        }
      }
    }

    for (int h = 0;h < H;h++){
      if (h%2 == 0){
        for (int w = 0;w < W;w++){
          cout << C.at(h).at(w) << " ";
        }
      }else{
        for (int w = 0;w < W;w++){
          cout << C.at(h).at(W-w-1) << " ";
        }
      }
      cout << endl;
    }

  }       