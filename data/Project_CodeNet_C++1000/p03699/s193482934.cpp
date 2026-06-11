#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int N;cin>>N;
  vector<int> s(N);rep(i,N) cin>>s[i];
  
  int sum=0;
  for(int i=0;i<N;i++) sum+=s[i];
  
  int count=0;
  for(int i=0;i<N;i++){
    if(s[i]%10==0) count++;
  }
  if(count==N){
    cout << 0 << endl;
    return 0;
  }
  
  int min_ans=110;
  if(sum%10!=0){
    cout << sum << endl;
    return 0;
  }
  else{
    for(int i=0;i<N;i++){
      if(s[i]%10!=0) min_ans=min(min_ans,s[i]);
    }
    
    cout << sum-min_ans << endl;
  }
}
 