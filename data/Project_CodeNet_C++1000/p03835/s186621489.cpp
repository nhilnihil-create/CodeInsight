#include <bits/stdc++.h>
using namespace std;

int main() {
  int S,K,sum=0; cin>>K>>S;
  for(int i=0; i<=K; i++) for(int j=0; j<=K; j++) {
  	if(0 <= S-i-j && S-i-j <= K) sum++;
  }
  cout<<sum<<endl;
}
