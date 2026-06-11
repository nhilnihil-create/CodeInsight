#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

int main() {
  int h,w; cin >> h >> w;
  vector<string> st(h);
  for(int i = 0; i < h; ++i) {
    cin >> st.at(i);
  }

  for(int i = 0; i < w+2; ++i) {
    cout << '#';
  }
  cout << endl;

  for(int i = 0; i < h; ++i) {
    cout << '#' << st.at(i) << '#' << "\n";
  }

  for(int i = 0; i < w+2; ++i) {
    cout << '#';
  }
}