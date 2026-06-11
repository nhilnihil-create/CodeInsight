#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> vector0(W+2);
  int i;
  for (i=0;i<W+2;i++) {
    vector0.at(i) = "#";
    cout << vector0.at(i);
  }
  cout <<endl;
 int j;
  for (j=0;j<H;j++) {
    string A;
    cout << "#";
    cin >> A;
    cout << A;
    cout << "#";
    cout <<endl;
  }
  vector<string> vector1(W+2);
  int l;
  for (l=0;l<W+2;l++) {
    vector1.at(l) = "#";
    cout << vector1.at(l);
  }
  
}