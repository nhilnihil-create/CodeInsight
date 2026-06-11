#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,A;
  cin>>N>>A;
  A--;
  int64_t a=2;
  for(int i=1;i<N;i++){
    int64_t b;
    cin>>b;
    if(a==b){
      a++;
    }
    else{
      b--;
      A+=b/a;
    }
  }
  cout<<A<<endl;
}