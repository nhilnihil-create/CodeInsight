#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll N; cin>>N;
  ll A,B; cin>>A>>B;
  ll C,D; cin>>C>>D;
  set<ll> high;
  bool j=false;
  if(A+D*(N-1)>=B){
    for(int i=0;i<N;i++){
      high.insert(A+D*(N-1)-i*(C+D));
    }
    auto x=high.lower_bound(B);
    if(*x-B<=(D-C)*(N-1)) j=true;
  }
  if(j)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}