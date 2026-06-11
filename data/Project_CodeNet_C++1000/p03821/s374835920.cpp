#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  vector<int64_t>B(N);
  for(int i=0;i<N;i++){
  int64_t a,b;
    cin>>a>>b;
    A.at(i)=a;
    B.at(i)=b;
  }reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  int64_t ans=0;
  for(int i=0;i<N;i++){
    A.at(i)+=ans;
 ans+=((B.at(i)+A.at(i)-1)/B.at(i))*B.at(i)-A.at(i);
  }cout<<ans<<endl;
   return 0;
}