#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> x(N);
  for (int i = 0; i < N; i++){
    cin >> x[i];
    if (x[i] - i > N * (N - 1) + 1 || x[i] < i){
      cout << "No" << endl;
      return 0;
    }
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  for (int i = 0; i < N; i++){
    if (i > 0){
      pq.push(make_tuple(x[i] - 1, i, i + 1));
    }
  }
  /*
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq2 = pq;
  while (!pq2.empty()){
    int pos, cnt, num;
    tie(pos, cnt, num) = pq2.top();
    pq2.pop();
    cout << "pos = " << pos << ", cnt = " << cnt << ", num = " << num << endl;
  }
  */
  vector<int> ans(N * N, 0);
  for (int i = 0; i < N; i++){
    ans[x[i] - 1] = i + 1;
  }
  bool ok = true;
  vector<int> c(N, 0);
  vector<bool> done(N, false);
  for (int i = 0; i < N * N; i++){
    if (ans[i] != 0){
      c[ans[i] - 1]++;
      done[ans[i] - 1] = true;
      continue;
    }
    if (!pq.empty()){
      int pos, cnt, num;
      tie(pos, cnt, num) = pq.top();
      pq.pop();
      //cout << "pos = " << pos << ", cnt = " << cnt << ", num = " << num << endl;
      if (i > pos){
        ok = false;
        break;
      }
      ans[i] = num;
      c[num - 1]++;
      if (cnt > 1){
        pq.push(make_tuple(pos, cnt - 1, num));
      }
    } else {
      bool exist = false;
      for (int j = 0; j < N; j++){
        if (done[j] && c[j] < N){
          ans[i] = j + 1;
          c[j]++;
          exist = true;
          break;
        }
      }
      if (!exist){
        ok = false;
        break;
      }
    }
  }
  if (ok){
    cout << "Yes" << endl;
    for (int i = 0; i < N * N; i++){
      cout << ans[i];
      if (i < N * N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}