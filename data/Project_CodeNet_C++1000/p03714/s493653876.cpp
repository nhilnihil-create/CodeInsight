#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(3 * N);
  for(int i = 0; i < 3 * N; i++) cin >> a[i];
  
  vector<long long> s_f(N + 1, 0);
  vector<long long> s_b(N + 1, 0);
  
  priority_queue<int> q_f;
  for(int i = 0; i < N; i++){
    s_f[0] += a[i];
    q_f.push(-a[i]);
  }
  
  for(int i = 0; i < N; i++){
    s_f[i + 1] = s_f[i];
    if(-q_f.top() < a[i + N]){
      s_f[i + 1] += q_f.top();
      s_f[i + 1] += a[i + N];
      q_f.pop();
      q_f.push(-a[i + N]);
    }
  }
  
  priority_queue<int> q_b;
  for(int i = 0; i < N; i++){
    s_b[0] += a[3 * N - i - 1];
    q_b.push(a[3 * N - i - 1]);
  }
  
  for(int i = 0; i < N; i++){
    s_b[i + 1] = s_b[i];
    if(q_b.top() > a[2 * N - i - 1]){
      s_b[i + 1] -= q_b.top();
      s_b[i + 1] += a[2 * N - i - 1];
      q_b.pop();
      q_b.push(a[2 * N - i - 1]);
    }
  }
  
  long long s = s_f[0] - s_b[N];
  for(int i = 1; i <= N; i++){
    s = max(s, s_f[i] - s_b[N - i]);
  }
  
  cout << s << endl;
  
  return 0;
}