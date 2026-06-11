#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){

  int N;
  int L;
  cin>>N>>L;
  vector<string>S(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>S[i];
  }
  sort(S.begin(),S.end());
  for(int i=0;i<=N-1;i++){
  
    cout<<S[i];
  }
}