#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int N,Ma,mb;
  cin>>N;
  int A[N],B[N];
  for(int i=0;i<N;i++) cin>>A[i]>>B[i];
  mb=B[0];
  Ma=A[0];
  for(int i=1;i<N;i++){
    mb=min(B[i],mb);
    Ma=max(A[i],Ma);
  }
  cout<<mb+Ma<<endl;
}

