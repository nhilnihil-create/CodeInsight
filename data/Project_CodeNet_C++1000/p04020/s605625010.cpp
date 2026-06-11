#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long count=0;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<N;i++){
    count+=A.at(i)/2;
    int B=A.at(i)%2;
    if(B==1 && i!=N-1 && A.at(i+1)!=0){
      A.at(i+1)--;
      count++;
    }
  }
  cout << count << endl;
} 