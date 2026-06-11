#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long>a(3*n);
  for(int i=0; i<3*n; i++)cin >> a[i];
  priority_queue<long>leftq, rightq;
  vector<long>lefts(n+1), rights(n+1);
  for(int i=0; i<n; i++)leftq.push(-a[i]);
  lefts[0]=accumulate(a.begin(), a.begin()+n, 0L);
  for(int i=1; i<=n; i++){
    if(-leftq.top()<a[n+i-1]){
      lefts[i]=lefts[i-1]-(-leftq.top())+a[n+i-1];
      leftq.pop();
      leftq.push(-a[n+i-1]);
    }
    else lefts[i]=lefts[i-1];
  }
  for(int i=2*n; i<3*n; i++)rightq.push(a[i]);
  rights[0]=accumulate(a.begin()+2*n, a.begin()+3*n, 0L);
  for(int i=1; i<=n; i++){
    if(rightq.top()>a[2*n-i]){
      rights[i]=rights[i-1]-rightq.top()+a[2*n-i];
      rightq.pop();
      rightq.push(a[2*n-i]);
    }
    else rights[i]=rights[i-1];
  }
  long ret=lefts[0]-rights[n];
  for(int i=0; i<=n; i++){
    ret = max(ret, lefts[i]-rights[n-i]);
  }
  for(int i=0; i<=n; i++){
    cerr << lefts[i] << ' ' << rights[n-i] << endl;
  }
  cout << ret;
  return 0;
}
