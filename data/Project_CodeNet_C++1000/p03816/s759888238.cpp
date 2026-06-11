#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  map<int,int> S;
  for(int i=0;i<N;++i){
    int A;
    cin>>A;
    ++S[A];
    S[A] %= 2;
  }

  int S_even=0,S_odd=0;
  for(auto p:S){
    if(p.second==1) ++S_odd;
    else ++S_even;
  }

  if(S_even%2==0) cout<<S_odd+S_even<<endl;
  else cout<<S_odd+S_even-1<<endl;
}
