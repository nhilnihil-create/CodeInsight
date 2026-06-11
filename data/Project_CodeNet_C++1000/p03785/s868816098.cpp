#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int64_t N,C,K;
  cin>>N>>C>>K;
  vector<int64_t> T(N);
  for(int i=0;i<N;i++) cin>>T.at(i);
  sort(T.begin(),T.end());
  int64_t a=0,i=0,count=1;
  for(int i=0;i<N;i++){
    if(i<a+C&&T.at(i)<=T.at(a)+K);
      else {
        a=i;
        count++;
      }
  }
  cout<<count;   
}
