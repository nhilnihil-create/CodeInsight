#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int K,S;
  cin >> K >> S;
  int count = 0;
  //0 < x,y,z < 2を満たす
  for(int i = 0; i <= K; i++){
    for(int j = 0; j <= K; j++){
      int d = S - i - j;//dの値
      if(d >= 0 && d <= K){
        count++;
      }
    }
  }
  cout << count << endl;


}