#include<bits/stdc++.h>
using namespace std;
int main(){
  set<int>list;
  for(int i=0;i<3;i++){
    int N;
    cin>>N;
    list.insert(N);
  }
  cout<<list.size()<<endl;
}