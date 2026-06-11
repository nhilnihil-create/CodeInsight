#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  int P,X;
  int sum =0;
  cin >> N;
  vector <int> T(N);
  for(int i = 0; i < N; i++){
    cin >> T.at(i);
  }
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> P >> X;
    P--;
    for(int k = 0; k < N; k++){
    	if(k != P) sum += T.at(k);
    	else	sum += X;
    }
    cout << sum << endl;
    sum = 0;
  }
  

}