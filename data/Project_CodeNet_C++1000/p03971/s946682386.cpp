#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  cin>>N>>A>>B;
  vector<char> vec(N);
  for(int i=0; i<N; i++){
    cin>>vec.at(i);
  }
  int apass=0;
  int bpass=0;
  for(int i=0; i<N; i++){
    if(vec.at(i)=='a'){
      if(apass<A+B&&apass+bpass<A+B){
        cout<<"Yes"<<endl;
        apass++;
      }
      else{
        cout<<"No"<<endl;
      }
    }
    else if(vec.at(i)=='b'){
      if((bpass<B)&&(apass+bpass<A+B)){
        cout<<"Yes"<<endl;
        bpass++;
      }
      else{
        cout<<"No"<<endl;
      }
    }
    else{
      cout<<"No"<<endl;
    }
  }
}