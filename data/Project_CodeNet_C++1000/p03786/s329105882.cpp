#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int64_t N;
  cin>>N;
  vector<int64_t> S(N);
  for(int i=0;i<N;i++) cin>>S.at(i);
  sort(S.begin(),S.end());
  int64_t total=S.at(0);
  for(int i=1;i<N;i++){
    if(2*total<S.at(i)) S.at(i-1)=0;
    total+=S.at(i);
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    ans++;
    if(S.at(i)==0) ans=0;
  }
  cout<<ans;
}
    
