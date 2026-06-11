#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MIN=-INT_MAX;

typedef long long ll;


int main(){
  int n, t; cin >> n >> t;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  priority_queue<int> PQ;
  int maxP=MIN, cnt=1;
  for(int i=n-2;i>=0;i--){
    PQ.push(a[i+1]);
    int t = PQ.top()-a[i];
    if(t == maxP){
      cnt++;
    }else{
      maxP = max(t, maxP);
    }
  }
  cout << cnt << endl;
}