#include <bits/stdc++.h>
using namespace std;

int main() {
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int N;
  cin>>N;

  int A=0,B=0;

  for(int i=0;i<N;i++){
    int At,Bt;
    cin>>At>>Bt;
    if(At>A) A=At,B=Bt;
  }
  cout<<A+B<<endl;
}
