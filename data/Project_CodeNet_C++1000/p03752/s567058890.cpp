#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k;
  cin >> n >> k;
  int64_t a[n];
  for(int64_t i=0;i<n;i++)cin >> a[i];
    int64_t ans=1000000000000000000;
  for(int64_t bit=0;bit<(1<<n);bit++){
    if(__builtin_popcount(bit)<k || bit%2==0)continue;
    vector<int64_t> s;
    for(int64_t i=0;i<n;i++){
      if(bit&(1<<i)){
          s.push_back(i);
      }
    }
    s.push_back(n);
    int64_t l=0,sum=0;
    for(int64_t j=0;j<s.size()-1;j++){
        l=max(l+1,*max_element(a+s[j],a+s[j+1]));
        sum+=l-a[s[j]];
    }
    ans=min(ans,sum);
  }
  cout << ans << endl;
}
