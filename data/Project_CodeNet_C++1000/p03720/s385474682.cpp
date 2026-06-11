#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> R(M*2); //道の情報
  for (int i = 0; i < R.size(); i++)
    cin >> R.at(i);
  vector<int> F(N+1, 0);//数え上げ用
  int count = 0;

  for (int j = 1; j <= N; j++){
      for (int i = 0; i < M*2; ){

        if(R.at(i) == j){

          F.at(R.at(i+1)) += 1;

        }else if(R.at(i+1) == j){

          F.at(R.at(i)) += 1;

        }

        i = i + 2;

      }

    for (int l = 0; l < F.size(); l++){
      count += F.at(l);
    }
      cout << count << endl;
      count = 0;
      F = vector<int>(N+1, 0);
  }

}
