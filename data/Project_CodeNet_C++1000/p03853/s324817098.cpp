#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> C(H);
  for(int i=0;i<H;i++){
    cin >> C[i];
  }
  vector<string> D(2*H);
  for(int i=0;i<2*H;i++){
    D[i]=C[i/2];
    cout << D[i] << endl;;
  }
}