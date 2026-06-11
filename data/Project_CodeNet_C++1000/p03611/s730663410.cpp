#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int>data(100005);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    data.at(x)++;
  }
  int ans=0;
  for(int i=1;i<100004;i++){
    ans=max(ans,data.at(i-1)+data.at(i)+data.at(i+1));
  }
  cout << ans << endl;
}