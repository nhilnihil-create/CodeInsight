//1 4 3 5 2
//4 1 3 5 2
//1 4 5 3 2
//手前かおくと交換、どっち優先か
//1 2 3 4 5 6
//2 1 3 4 5 6
//2 1 4 3 6 5
//1手先か
//1 4 3 2 5
//4 1 3 2 5
//4 1 2 3
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,tmp=1, ans=0; cin>>N;
  for(int i=0; i<N; i++,tmp++){
    ll p; cin>>p;
    if(p==tmp){
      i++; tmp++; cin>>p; ans++;
    }
  }
  cout<<ans<<endl;
}