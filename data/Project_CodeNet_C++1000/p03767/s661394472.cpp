#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N*3);
  
  for (int i=0; i<N*3; i++)
    cin >> vec.at(i);
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  long sum = 0;
  for (int i=1; i<=N*2; i+=2)
    sum += vec.at(i);
  
  cout << sum << endl;
}