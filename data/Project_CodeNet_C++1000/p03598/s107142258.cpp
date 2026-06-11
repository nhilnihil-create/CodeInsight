#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,A,B,sum;
  cin >> N >>K;
  sum=0;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    A = K-x;
    B = min(x,A);
    sum += B*2;
  }
  cout<<sum<<endl;
}
