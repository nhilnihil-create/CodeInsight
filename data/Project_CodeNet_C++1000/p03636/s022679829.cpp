#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int N=S.size();
  int K=N-2;
  cout<<S.at(0)<<K<<S.at(N-1)<<endl;
}