#include <bits/stdc++.h>
using namespace std;


int main() {


  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }

  int64_t cost_min=100000000000000000;
  for(int i=-100;i<=100;i++){
    int64_t cost_wk=0;
    for(int j=0;j<n;j++){
      cost_wk+=pow(a.at(j)-i,2);
    }
    cost_min = min(cost_min, cost_wk);
  }

  cout<<cost_min<<endl;

  return 0;
}

