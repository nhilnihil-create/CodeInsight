#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(3*N);
  for (int i=0; i<3*N; i++) cin >> a[i];
  long long mae = 0;
  priority_queue<int, vector<int>, greater<int> > maeval;
  for (int i=0; i<N; i++){
    mae += a[i];
    maeval.push(a[i]);
  }
  long long usiro = 0;
  priority_queue<int> usiroval;
  for (int i=0; i<N; i++){
    usiro += a[3*N-1-i];
    usiroval.push(a[3*N-1-i]);
  }

  vector<long long> maescore(N+1);
  vector<long long> usiroscore(N+1);
  maescore[0] = mae;
  usiroscore[0] = usiro;
  for (int i=0; i<N; i++){
    if (a[N+i] > maeval.top()){
      mae += a[N+i]-maeval.top();
      maeval.pop();
      maeval.push(a[N+i]);
    }
    maescore[i+1] = mae;
    if (a[2*N-1-i] < usiroval.top()){
      usiro -= usiroval.top() - a[2*N-1-i];
      usiroval.pop();
      usiroval.push(a[2*N-1-i]);
    }
    usiroscore[i+1] = usiro;
  }
  long long ans = -100000000000000;
  for (int i=0; i<N+1; i++) ans = max(ans, maescore[i]-usiroscore[N-i]);
  // for (int i=0; i<N+1; i++) {
  //   cout << "mae" << i << ": " << maescore[i] << endl;
  //   cout << "usiro" << i << ": " << usiroscore[i] << endl;
  //   cout << endl;
  // }
  cout << ans << endl;
}
