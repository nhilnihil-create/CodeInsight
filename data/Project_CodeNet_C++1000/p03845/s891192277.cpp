#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M;

  cin >> N;

  vector<int> T(N);
  for (int i = 0; i < N; i++)
  {
    cin >> T.at(i);
  }
  
  cin >> M;

  vector<pair<int, int>> PM(M);
  for (int i = 0; i < M; i++)
  {
    cin >> PM.at(i).first >> PM.at(i).second;
  }
  
  int sum;
  for (int i = 0; i < M; i++)
  {
    sum = 0;
    for (int j = 0; j < N; j++)
    {
      if (j + 1 == PM.at(i).first){
        sum += PM.at(i).second;
      }
      else
      {
        sum += T.at(j);
      }
      
    }
    cout << sum << endl;
  }
  
}