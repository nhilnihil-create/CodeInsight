#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N ;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A.at(i);
  int LED = 1;
  vector<int> count(N,0);
  count.at(0) = 1;

  while(1){
     LED = A.at(LED-1);

     if(count.at(LED-1) == 1){
       
       LED = -1;
     	 break;

     }else if(LED == 2){

       LED = 0;
       for (int i = 0; i < N; i++)
        LED += count.at(i);
       //LED++;
       break;

     }else{

       count.at(LED-1) = 1;

     }
  }
  cout << LED << endl;
}
