#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int K;
  cin>>N>>K;
  int A=0;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    A+=x*2;
    if(x>K-x){
      A-=x*2;
      A+=(K-x)*2;
    }
  }
  cout<<A<<endl;
}
