#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> fr(0), ba(0);
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    if(i % 2) ba.push_back(a);
    else fr.push_back(a);
  }
  
  if(n % 2){
    reverse(fr.begin(), fr.end());
    for(auto a : fr) cout << a << " ";
    for(auto a : ba) cout << a << " ";
  }
  else{
    reverse(ba.begin(), ba.end());
    for(auto a : ba) cout << a << " ";
    for(auto a : fr) cout << a << " ";
  }
  cout << endl;
}