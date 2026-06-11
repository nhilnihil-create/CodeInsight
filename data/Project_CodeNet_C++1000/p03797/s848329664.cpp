#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int N, M;
  cin>>N>>M;

  long long int answer=0;

  if(N>=M/2){
    answer+=M/2;
  }else if(N<M/2){
    answer+=N;
    answer+=(M-2*N)/4;
  }

  cout<<answer<<endl;

}
