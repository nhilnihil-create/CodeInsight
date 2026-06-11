#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[N - 1] - a[0] > 1){
    cout << "No" << endl;
  } else if (a[0] == a[N - 1]){
    if (a[0] * 2 <= N || a[0] == N - 1){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    int cnt = upper_bound(a.begin(), a.end(), a[0]) - a.begin();
    if (cnt > a[0]){
      cout << "No" << endl;
    } else {
      if (a[0] < N / 2){
        cout << "Yes" << endl;
      } else {
        if (a[N - 1] * 2 - N <= cnt){
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
  }
}