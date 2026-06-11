#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
 string S;
  cin>>S;
  int x=0;

  vector<int> b(N);
  for(int i=0;i<N;i++){
    if(S.at(i)=='I'){
      x++;

      b.at(i)=x;
    }
    else{
      x--;
 
    b.at(i)=x;   
  }
  }

  sort(b.begin(),b.end());
  cout<<max(0,b.at(N-1))<<endl;

 
}