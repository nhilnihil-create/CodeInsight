#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
#define PI 3.14159265359

const int mod = 1e9 + 7;

int sum(long long left, long long right){
  long long ret = (right+left) * (right-left+1) / 2;
  return ret;
}

int N;
int H, W;

void print_table(vector<int> vect){

  int h = 0;
  int w = 0;

  int field[H][W];

  // insert
  rep(i, N){
    int grid = vect[i];
    rep(j, grid){
      // insert
      field[h][w] = i+1;
      // move
      if(w==0 && h%2==1){
        h++;
      }else if(w==W-1 && h%2==0){
        h++;
      }else if(h%2==0){
        w++;
      }else if(h%2==1){
        w--;
      }
    }
  }

  // draw
  rep(i, H){
    rep(j, W){
      if(j!=0) cout << " ";
      cout << field[i][j];
    }
    cout << endl;
  }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

  cin >> H >> W;
  cin >> N;

  vector<int> vect;

  rep(i, N){
    int tmp;
    cin >> tmp;
    vect.push_back(tmp);
  }

  print_table(vect);
}
