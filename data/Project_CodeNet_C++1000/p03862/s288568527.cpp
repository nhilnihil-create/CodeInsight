#include <bits/stdc++.h>
using namespace std;

 
int main(){

  int N,x;
  cin>>N>>x;
  vector<int> num(N);
  for(int i=0; i<N; i++){
    cin>>num.at(i);
  }
  
  long long ans=0;
  if (num[0]>x){
    ans += num[0]-x;
    num[0] -= num[0]-x;
  }
  for(int i=0; i<N-1; i++){
    if(num[i]+num[i+1]>x){
         ans += (num[i]+num[i+1])-x;
         num[i+1] -= (num[i]+num[i+1])-x;
    }
  }
  cout<<ans<<endl;
  
 return 0; 
}