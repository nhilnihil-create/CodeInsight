#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> array(n);
  for(int i = 0; i < n; i++){
    cin >> array.at(i);
  }
  sort(array.begin(),array.end(),greater<int>());
  int sum = 0;
  for(int i = 0; i < k; i++){
    sum += array.at(i);
  }
  cout << sum << endl;
}