#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int size = S.size();
  int space = size - 1;
  
  long long ans = 0;
  for (int tmp = 0; tmp < (1 << space); tmp++){
    bitset<10> s(tmp);
    vector<long long> flag;
    int point = 0;
    for (int i = 0; i < space; i++){
      if (s.test(i)){
        string push = S.substr(point, i + 1 - point);
        long long pushing = stoll(push);
        flag.push_back(pushing);
        point = i + 1;
      }
    }
    string push_last = S.substr(point, size - point);
    long long pushing_last = stoll(push_last);
    flag.push_back(pushing_last);
    long long sum = 0;
    for (long long a : flag){
      sum += a;
    }
    ans += sum;
  }
  
  cout << ans << endl;
}
