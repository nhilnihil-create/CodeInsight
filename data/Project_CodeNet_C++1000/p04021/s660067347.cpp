#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  vector<pair<int,int>>vec;
  for(int i=0;i<N;i++){
    cin>>A[i];
    vec.push_back({A[i],i});
  }
  sort(vec.begin(),vec.end());
  int cnt=0;
  for(int i=0;i<N;i++){
    //cout<<vec.at(i).second<<" "<<i<<endl;
    if((vec.at(i).second-i)%2 !=0){
      cnt++;
    }
  }
  cout<<cnt/2<<endl;
  return 0;
}
