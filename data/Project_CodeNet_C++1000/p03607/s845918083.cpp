#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  long long cnt = 0;
  cin >> num;
  
  map<long long, long long> m;
  long long tmp;
  
  for(int i = 0; i < num; i++){
    cin >> tmp;
    m[tmp] += 1;
  }
  
  for(auto itr:m){
    if(itr.second % 2 != 0) cnt++;
  }
  
  cout << cnt;
}
