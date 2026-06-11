#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int a=0;
  int N=S.size();
  for(int i=0;i<N;i++){
    long long count=0;
    for(int j=0;j<N;j++){
      if(S.at(i)==S.at(j)){
        count++;
      }
    }
    if(count%2==1)
      a=1;
  }
  if(a==1)
    cout<<"No"<<endl;
  else
   cout<<"Yes"<<endl;
}
