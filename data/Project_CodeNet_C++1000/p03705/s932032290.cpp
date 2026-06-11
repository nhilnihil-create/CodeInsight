#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll N, A, B; cin>>N>>A>>B;
  if(A>B) cout<<0<<endl;
  else if(N==1 && A!=B) cout<<0<<endl;
  else{
    cout<<(B*(N-1)+A)-(A*(N-1)+B)+1<<endl;
  }
}
