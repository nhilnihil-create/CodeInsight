#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int>data(N);
  for(int i=0;i<N;i++){
    cin >> data.at(i);
  }
  sort(data.begin(),data.end());
  reverse(data.begin(),data.end());
  int result=0;
  for(int i=0;i<K;i++){
    result+=data.at(i);
  }
  cout << result << endl;
}
