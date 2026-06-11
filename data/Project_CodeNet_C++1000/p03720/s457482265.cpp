#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> a(2*M);
  for(int i=0; i<2*M; i++){
    cin >> a.at(i);
  }
  for(int i=1; i<=N; i++){
    int counter = 0;
    for(int j=0; j<2*M; j++){
      if(a.at(j)==i){
        counter++;
      }
    }
    cout << counter << endl;
  }
  return 0;
}