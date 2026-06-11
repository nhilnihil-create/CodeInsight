#include<bits/stdc++.h>
using namespace std;

int main() {
  int kazu,size;
  cin >> kazu >> size;
  vector<string> kekka(kazu);
  for(int i=0;i<kazu;i++) {
    cin >> kekka.at(i);
  }
  sort(kekka.begin(),kekka.end());
  for(int i=0;i<kazu;i++) {
    cout << kekka.at(i);
  }
}