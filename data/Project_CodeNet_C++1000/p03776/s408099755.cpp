#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, A, B;
  cin >> N >> A >> B;
  vector<pair<long,long>> data(N + 1);
  data.at(0).first = 1;
  long a;
  for(long i = 0; i < N; i++){
    cin >> a;
    for(long j = N - 1; j >= 0; j--){
      if(data.at(j).first >= 1){
        if(data.at(j + 1).second == data.at(j).second + a){
          data.at(j + 1).first += data.at(j).first;
        } else if(data.at(j + 1).second < data.at(j).second + a){
          data.at(j + 1).second = data.at(j).second + a;
          data.at(j + 1).first = data.at(j).first;
        }
      }
    }
  }
  map<double, long> mp;
  for(long i = A; i <= B; i++){
    if(data.at(i).second % i == 0)mp[data.at(i).second / i] += data.at(i).first;
    else mp[data.at(i).second / ((double)i)] += data.at(i).first;
  }
  auto c = mp.end();
  c--;
  cout << setprecision(100) << c->first << endl;
  cout << c->second << endl;
  return 0;
}