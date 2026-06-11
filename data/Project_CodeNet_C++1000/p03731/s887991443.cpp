#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,T;
  long long ans;
  cin >> n >> T;
  vector<long>data(n);
  ans = n*T;
  for(long i;i < n;i++){
    cin >> data[i];
    if(i != 0){
      if(data[i]-data[i-1] < T){
        ans -= T-(data[i]-data[i-1]);
      }
    }
  }
  cout << ans << endl;
}
