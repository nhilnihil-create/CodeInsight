#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<(int)c;i++)
#define print(var) cout<<var<<endl;
#define DEBUG(var) cerr<<var<<endl;
// puts("str");

const int inf = 1000000000;//10^9

int main (){
  int N;
  int count=0;
  cin>>N;
  vector<int> A(N);
  rep(i,N) {
    cin >>A[i];
    A[i]--;
  }
  rep(i,N){
    if(A[A[i]]==i){
      count++;
    }
  }

  cout<<count/2<<endl;

  return 0;

}
