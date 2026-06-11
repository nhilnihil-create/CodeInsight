#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  double sum = 0.0;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++){
    cin >> v[i];    
    sum += v[i];
  }
  int e = round(sum/N);
//  cout << e << endl;
  int Ans = 0;
  for (int i = 0; i < N; i++){
    Ans += (v[i]-e)*(v[i]-e);
  }
  cout << Ans << endl;
  return 0;  
}