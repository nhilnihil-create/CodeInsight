#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t n;
  cin>>n;

  map<int64_t, int64_t> a;
  for(int i=0;i<n;i++){
    int64_t wk;
    cin>>wk;
    if(a.count(wk))
      a.at(wk)++;
    else
      a[wk]=1;
  }


  int64_t k0=0,k1=0,k2=0;
  int64_t wk0=0,wk1=0,wk2=0;
  int64_t max_sum=0;
  for (auto p : a) {
    auto k = p.first;
    auto v = p.second;

    k2 = k1;
    k1 = k0;
    k0 = k;

    wk2=wk1;
    wk1=wk0;
    wk0=v;

  if((abs(k0-k1)<=1) &&abs ((k1-k2)<=1))
      max_sum=max(wk0+wk1+wk2,max_sum);
  else if((abs(k0-k1)<=1))
      max_sum=max(wk0+wk1,max_sum);
  else if(abs ((k1-k2)<=1))
      max_sum=max(wk2+wk1,max_sum);
  }

  if(n==1)
    cout<<1<<endl;
  else
    cout<<max_sum<<endl;

	return 0;
}