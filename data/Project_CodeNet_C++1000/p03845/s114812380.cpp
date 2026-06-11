#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,sum=0;
  cin>>N;
  vector<int> t(N);
  for(int i=0;i<N;i++)
    cin>>t.at(i);
  cin>>M;
  vector<int> p(M);
  vector<int> x(M);
  for(int i=0;i<M;i++)
    cin>>p.at(i)>>x.at(i);
  for(int i=0;i<N;i++)
    sum+=t.at(i);
  for(int i=0;i<M;i++){
    int a=sum-t.at(p.at(i)-1)+x.at(i);
    cout<<a<<endl;
  }
}
