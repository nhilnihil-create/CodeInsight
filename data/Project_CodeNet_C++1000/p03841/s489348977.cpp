#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<pair<int, int>> x(N);
  for(int i = 0; i < N; i++){
    cin >> x[i].first;
    x[i].second = i;
    --x[i].first;
  }
  sort(x.begin(), x.end());
  
  vector<int> a(N * N, -1);
  bool able = true;
  for(int i = 0; able && i < N; i++){
    if(a[x[i].first] != -1) able = false;
    a[x[i].first] = x[i].second;
    
    int cnt = 0;
    for(int j = 0; j < x[i].first && cnt < x[i].second; j++){
      if(a[j] == -1){
        a[j] = x[i].second;
        ++cnt;
      }
    }
    
    if(cnt != x[i].second) able = false;
  }
  
  for(int i = N - 1; able && i >= 0; i--){
    int cnt = 0;
    for(int j = N * N - 1; j > x[i].first && cnt < N - x[i].second - 1; j--){
      if(a[j] == -1){
        a[j] = x[i].second;
        ++cnt;
      }
    }
    
    if(cnt != N - x[i].second - 1) able = false;
  }
  
  if(able){
    puts("Yes");
    for(int i = 0; i < N * N - 1; i++) cout << a[i] + 1 << ' ';
    cout << a[N * N - 1] + 1 << endl;
  }else puts("No");
  
  return 0;
}