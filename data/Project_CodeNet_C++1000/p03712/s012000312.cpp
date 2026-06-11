#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> h(H);
  vector<string> w(W);
  
  for(int i=0; i<W; i++){
    w.push_back("#");
  }
  w.push_back("##");
  
  string sum;
  for(int i=0; i<w.size(); i++){
    sum += w.at(i);
  }
  cout << sum << endl;
  
  for(int i=0; i<H; i++){
    cin >> h.at(i);
  }
  
  string sum1;
  for(int i=0; i<H; i++){
    sum1 += h.at(i);
    
    if(sum1.size() == W){
      cout << "#" << sum1 << "#" << endl;
      sum1 = "";
    }
    
  }
  cout << sum << endl;
}
