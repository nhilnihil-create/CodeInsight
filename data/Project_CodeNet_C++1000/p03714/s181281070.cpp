#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  priority_queue<long> right;
  priority_queue<long,vector<long>,greater<long>> left;
  vector<long> suml(n+1),sumr(n+1);
  long a[3*n];
  for(int i = 0;i < 3*n;i++){
    cin >> a[i];
    if(i < n){ 
      left.push(a[i]);
      suml.at(0) += a[i];
    }
    else if(i >= 2*n){
      right.push(a[i]);
      sumr.at(0) += a[i];
    }
  }
  for(int i = 0;i < n;i++){
    left.push(a[i+n]);
    suml.at(i+1) = suml.at(i) + a[i+n] - left.top();
    left.pop();
  }
  for(int i = 0;i < n;i++){
    right.push(a[2*n-i-1]);
    sumr.at(i+1) = sumr.at(i) + a[2*n-i-1] - right.top();
    right.pop();
  }
  long ans = suml.at(0) - sumr.at(n);
  //cout << suml.at(0) << ' ' << sumr.at(0) << endl;
  for(int i = 1;i <= n;i++){
    ans = max(ans,suml.at(i) - sumr.at(n-i));
    //cout << suml.at(i) << ' ' << sumr.at(i) << endl;
  }
  cout << ans << endl;
}