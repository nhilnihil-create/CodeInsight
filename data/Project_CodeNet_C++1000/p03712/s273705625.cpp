#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int h,w;
cin >> h >> w;
vector<vector<char>> A(h+2,vector<char>(w+2));

for(int i = 0; i < h+2; i++){
  for(int j = 0; j < w+2; j++){
    if(i == 0 || i == h+1 || j == 0 || j == w+1) A.at(i).at(j) = '#';
    else{
      char x;
      cin >> x;
      A.at(i).at(j) = x;
    }
  }
}
for(int i = 0; i < h+2; i++){
  for(int j = 0; j < w+2; j++){
    cout << A.at(i).at(j);
    if(j == w+1) cout << endl;
  }
}

  }
