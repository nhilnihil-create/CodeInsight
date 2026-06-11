#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
  int N,M;	//N個の都市、M本の道路
  cin>>N>>M;
  vector<int> a(M),b(M),total(N);
  for(int ni =0;ni<M;ni++)
  {
    cin>>a.at(ni)>>b.at(ni);
    total.at(a.at(ni)-1)++;
    total.at(b.at(ni)-1)++;
  }
  
  for(int ni=0;ni<N;ni++)
  {
    cout<<total.at(ni)<<endl;
  }
  return 0;
}