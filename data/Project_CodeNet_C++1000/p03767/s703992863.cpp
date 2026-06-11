#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long sum=0;
  cin >> N;
  vector<long long> A(3*N);
  for(int i=0;i<3*N;i++){
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  for(int i=0;i<2*N;i++){
    if(i%2==1){
      sum+=A.at(i);
    }
  }
  cout << sum << endl;
}
    
