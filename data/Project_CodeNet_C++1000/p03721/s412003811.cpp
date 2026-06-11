#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,K;
  cin>>N>>K;
  vector<pair<long long,long long>>vec;
  long long a,b;
  for(int i=0;i<N;i++){
    cin>>a>>b;
    vec.emplace_back(a,b);
  }
  sort(vec.begin(),vec.end());
  long long itr=0;
  while(1){
    //cout<<itr<<" "<<vec[itr].first<<" "<<vec[itr].second<<" "<<K<<endl;
    K-=vec[itr].second;
    if(K<=0) break;
    itr++;

  }
  cout<<vec[itr].first<<endl;

  return 0;
}


  