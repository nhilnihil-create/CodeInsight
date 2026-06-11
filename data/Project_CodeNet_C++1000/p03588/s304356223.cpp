#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int S = 0;
  int answer;
  int A , B;
  for(int i = 0; i < N; i++){
    cin >> A >> B;
    if(A > S){
      S = A;
      answer = A + B;
    }
  }
  cout << answer << endl;
}