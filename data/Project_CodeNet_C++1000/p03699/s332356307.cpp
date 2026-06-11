#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,sum=0;
  cin>>N;
  vector<int> v(N);
  for(int i=0;i<N;i++) cin>>v[i];
  
  sort(v.begin(),v.end());

  for(int i=0;i<N;i++) sum+=v[i];
    
  if(sum%10!=0) cout<<sum;
   
  else{
    int c=0;
    for(int i=0;i<N;i++){
      if(v[0]%10==0){
        v.erase(v.begin());
        c++;
      }
    }
  
    if(c==N) cout<<0;
    else cout<<sum-v[0];
  }
}