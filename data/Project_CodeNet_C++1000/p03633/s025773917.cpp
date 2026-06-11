#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin>>N;
  int64_t k=1;
  for(int64_t i=0;i<N;i++){
    int64_t j;
    cin>>j;
    k=k/__gcd(k,j)*j;
  }
  cout<<k<<endl;
}