#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  int64_t L; cin>>L;
  vector<int64_t>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int64_t ans=0;
  for(int i=0;i<N-1;i++)
    if(L<=a.at(i)+a.at(i+1)){ans=i+1; break;}
  if(ans==0)
    cout<<"Impossible"<<endl;
  else{
    cout<<"Possible"<<endl;
    for(int i=1;i<ans;i++)
      cout<<i<<endl;
    for(int i=N-1;ans<i;i--)
      cout<<i<<endl;
    cout<<ans<<endl;
 }
  return 0;
}