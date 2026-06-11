#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N,A,B,S;
  S=0;
  cin>>N;
  rep(i,N){
  cin>>A>>B;
  S+=B-A+1;
  }
  cout<<S<<endl;
}