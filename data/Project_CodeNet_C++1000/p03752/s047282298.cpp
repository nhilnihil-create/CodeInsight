#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;


int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  long long ans = -1;
  for(int i=0;i<(1<<(n-1));i++){
    bitset<14> b(i);
    int c = b.count();
    if(c == k-1){
      long long sum = 0;
      int saidai = a.at(0);
      for(int j=0;j<n-1;j++){
        if(b.test(j)){
          if(a.at(j+1) <= saidai){
            saidai++;
            sum += saidai-a.at(j+1);
          }
        }
        if(a.at(j+1)>saidai){
          saidai = a.at(j+1);
        }
      }
      if(ans < 0){
        ans = sum;
      }
      else{
        ans = min(ans,sum);
      }
    }
  }
  cout << ans << endl;
}