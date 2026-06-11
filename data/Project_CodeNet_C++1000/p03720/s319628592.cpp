#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector <vector <int> > input(M, vector<int>(2));
  vector<int> output(N, 0);
  for (int i = 0; i <M; ++i){
    cin >> input.at(i).at(0) >> input.at(i).at(1);
  }
  for (int i= 0; i < N; ++i){
    for (int j = 0; j < M; ++j){
      for (int k = 0; k < 2; ++k){
        if(i+1 == input.at(j).at(k)){
          ++output.at(i);
        }
      }
    }
  }
 for (int i = 0; i < N; ++i){
   cout << output.at(i) << endl;
 }
}
