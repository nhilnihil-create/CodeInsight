#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;
int main(){
  int N;
  cin>>N;
  vector<int64_t>a(3*N);
  for(int i=0;i<3*N;i++){
    cin>>a.at(i);
  }

  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
 
  int64_t ans=0;
  int count=1;
  int i=0;
  while(count<=N){
    if(i%2>0){ans+=a.at(i);
     count++;
    }
    i++;
  }
  cout<<ans<<endl;
  return 0;
}