#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N){
    cin >> a[i];
  }
  int cnt = 0;
  rep(i, N){
    //through same diff
    while(i + 1 < N && a[i] == a[i+1]) i++;

    if(a[i] < a[i+1] && i+1 < N){
      //when diff is plus
      while(i + 1 < N && a[i] <= a[i+1]) i++;
    }else if(i + 1 < N && a[i] > a[i+1]){
      //when diff is minus
      while(i + 1 < N && a[i] >= a[i+1]) i++;
    }
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
