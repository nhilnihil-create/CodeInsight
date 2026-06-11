#include <bits/stdc++.h>
using namespace std;
int main (){
  int N;
  cin>>N;
  vector<int> train(N);
  for(int i=0;i<N;i++){
    cin>>train.at(i);
  }
  int s=1;
  int n=0;
  for(int i=0;i<N;i++){
    s=train.at(s-1);
    n++;
    if(s==2){
      cout<<n<<endl;
      break;
    }
    else if(i==N-1){
      cout<<"-1"<<endl;
      break;
    }
  }
}
