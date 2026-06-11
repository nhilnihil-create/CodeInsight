 #include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (auto& s : A) cin >> s;
  int mono, bi, tetra;
  mono = bi = tetra = 0;
  vector<int> tally(26);
  for (auto s : A) for (auto c : s) tally[c - 'a']++;
  for(int x : tally) {
    if (!x) continue;
    tetra += x / 4; x %= 4;
    bi += x / 2; x %= 2;
    mono += x;
  }
  
  bool f=false;
  if (H % 2 && W % 2){
    f = (mono == 1 && bi <= H / 2 + W / 2);
  }
  else if (H % 2){
    f = (mono == 0 && bi <= W / 2);
  }
  else if (W % 2){
    f = (mono == 0 && bi <= H / 2);
  }
  else{
    f = (mono == 0 && bi == 0);
  }
  cout << (f ? "Yes" : "No") << endl;
}