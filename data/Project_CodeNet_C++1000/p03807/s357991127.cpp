#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int count=0;
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    if(A.at(i)%2==1){
      count++;
    }
  }
  if(count%2==0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
  
  