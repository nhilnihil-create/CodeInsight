#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(3*N), b(3*N);
  for(int i=0; i<3*N; i++) {
    cin >> a.at(i);
    //b.at(i)=a.at(i);
  }
  sort(a.begin(), a.end(), greater<int>());
  //reverse(a, a+N);
  long long ans=0;
  for(int i=1; i<2*N+1; i+=2) {
    ans+=a.at(i);
    //cout << a.at(i) << endl;
  }
  cout << ans << endl;
}