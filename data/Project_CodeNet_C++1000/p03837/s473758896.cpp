#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, M;
  cin >> N >> M;
  vector<vector<pair<long, long>>> data(N, vector<pair<long, long>> (N,make_pair(INT_MAX, 0)));
  long a, b, c;
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    a--;
    b--;
    data.at(a).at(b).first = c;
    data.at(a).at(b).second = 1;
    data.at(b).at(a).first = c;
  }
  for(int i = 0; i < N; i++)data.at(i).at(i).first = 0;
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(data.at(i).at(j).first > data.at(i).at(k).first + data.at(k).at(j).first){
          data.at(i).at(j).first = data.at(i).at(k).first + data.at(k).at(j).first;
          data.at(i).at(j).second = 0;
        }
      }
    }
  }
  long count = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      count += data.at(i).at(j).second;
    }
  }
  cout << M - count << endl;
  return 0;
}