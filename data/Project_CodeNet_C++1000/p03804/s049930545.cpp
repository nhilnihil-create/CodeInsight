#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

const long long INF = 1LL << 60;

int main() {
  int N, M;
  cin >> N >> M;
  string c, d;
  char a[N][N];
  char b[M][M];
  
  rep(i, N){
    cin >> c;
    rep(j, N){
      a[i][j] = c[j];
    }
  }

  rep(i, M){
    cin >> d;
    rep(j, M){
      b[i][j] = d[j];
    }
  }

  // 含むかどうかみていく
  bool flag = false;
  rep(i, N-M+1){
    rep(j, N-M+1){
      if(a[i][j] == b[0][0]){
        flag = true;
        for(int k = 0; k < M; k++){
          for(int l = 0; l < M; l++){
            if(a[k+i][l+j] != b[k][l]) {
              flag = false;
              break;
            }
          }
        }
        if(flag){
          print("Yes");
          return 0;
        }
      }
    }
  }
  
  print("No");

}
