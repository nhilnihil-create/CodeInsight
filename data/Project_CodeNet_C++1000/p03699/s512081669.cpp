#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=vec.at(i);
  }
  if(sum%10!=0){
    cout<<sum<<endl;
    return 0;
  }
  else{
    for(int i=0;i<N;i++){
      if(vec.at(i)%10!=0){
        sum-=vec.at(i);
        cout<<sum<<endl;
        return 0;
      }
    }
    cout<<0<<endl;
  }
}