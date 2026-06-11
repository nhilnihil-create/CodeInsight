#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int answer = 1;
  vector<int> a(n);
  int zogen = 0;//増加1→、減少-1→、初期値→0
  if (n == 1 || n == 2) goto OWA;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  for (int i = 1; i < n; i++) {//どこから始める？
    if(zogen == 1 && a[i-1] <= a[i]) continue;
    else if(zogen == 1 && a[i-1] > a[i]) {
      answer++;
      zogen = 0;
    }else if(zogen == -1 && a[i-1] < a[i]) {
      answer++;
      zogen = 0;
    }else if(zogen == -1 && a[i-1] >= a[i]) continue;
    else if(zogen == 0 && a[i-1] < a[i]) zogen = 1;
    else if(zogen == 0 && a[i-1] > a[i]) zogen = -1;
  }
  OWA:
  cout << answer;
}