#include <bits/stdc++.h>
using namespace std;
int N,K;
int main(){
  cin >> N;
  cin >> K;
  int distance = 0;
  for(int i=0;i<N;i++){
    int place;
    cin >> place;
    distance +=  2 * (K - place < place ? K - place : place);
  }
  cout << distance << endl;

}