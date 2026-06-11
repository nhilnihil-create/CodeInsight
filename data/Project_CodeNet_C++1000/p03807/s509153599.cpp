#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int numodd = 0;
  for(int i=0; i<N; i++){
    cin >> A.at(i);
    if(A.at(i)%2!=0){
      numodd++;
    }
  }
  if(numodd%2==0){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}