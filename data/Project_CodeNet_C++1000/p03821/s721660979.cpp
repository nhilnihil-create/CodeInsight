#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  vector<P>data(n);
  for(int i = 0;i< n;i++) cin >> data[i].first >> data[i].second;
  for(int i = n-1;i >= 0;i--){
    int mod = (sum+data[i].first)%data[i].second;
    if(mod == 0) continue;
    sum += data[i].second-mod;
  }
  cout << sum << endl;
}
