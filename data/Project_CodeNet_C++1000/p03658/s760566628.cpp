#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
 vector<int>data(60);
  for(int i=0;i<N;i++){
  cin>>data.at(i);
  }
  sort(data.begin(),data.end());
  reverse(data.begin(),data.end());
  int count;
  for(int i=0;i<K;i++){
  count =count+data.at(i);
  }
  cout<<count<<endl;
}