#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec_start(n), vec_end(n);
  int sum= 0;
  
  for(int i= 0; i< n; i++){
    cin >> vec_start.at(i) >> vec_end.at(i);
    sum += vec_end.at(i) - vec_start.at(i) + 1;
  } 
  cout << sum << endl;
}