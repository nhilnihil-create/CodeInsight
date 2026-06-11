#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  deque<int> a;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    if(i%2==0)
      a.push_back(j);
    else
      a.push_front(j);
  }
  if(N%2==0){
    for(int i=0;i<N-1;i++)
      cout<<a.at(i)<<' ';
    cout<<a.at(N-1)<<endl;
  }
  else{
    for(int i=N-1;i>0;i--)
      cout<<a.at(i)<<' ';
    cout<<a.at(0)<<endl;
  }
}