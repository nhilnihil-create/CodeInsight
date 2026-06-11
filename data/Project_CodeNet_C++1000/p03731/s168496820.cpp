#include <bits/stdc++.h>
using namespace std;

int main(){
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int N,T;
  cin>>N>>T;

  vector<int> t(N);
  for(int i=0;i<N;i++) cin>>t.at(i);

  int ima=0;
  int kako=0;
  int oyu=0;

  for(int i=0;i<N-1;i++){
    ima = ima + T;
    if(ima>t.at(i+1)){
      ima = t.at(i+1);
      oyu += (ima-kako);
    }
    else{
      oyu += T;
      ima = t.at(i+1);
    }
    kako = ima;
  }
  oyu += T;

  cout<<oyu<<endl;

}