#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(100002, 0);
  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    
    A.at(a)++;
    A.at(a + 1)++;
    A.at(a + 2)++;
  }
  
  int ans = 0;
  for (int i = 0; i < 100002; i++){
    ans = max(ans, A.at(i));
  }
  
  cout << ans << endl;
}