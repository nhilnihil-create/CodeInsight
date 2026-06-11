#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  set<int> A;
  int k=0;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    if(j<3200)
      A.insert(j/400);
    else
      k++;
  }
  cout<<max(1,(int)A.size())<<' '<<(int)A.size()+k<<endl;
}