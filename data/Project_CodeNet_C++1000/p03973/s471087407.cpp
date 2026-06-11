#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t ans=A.at(0)-1;int64_t a=2;
  for(int i=1;i<N;i++){
  if(A.at(i)==a)a++;
    else
      ans+=(A.at(i)-1)/a;
  }cout<<ans<<endl;
   return 0;
}