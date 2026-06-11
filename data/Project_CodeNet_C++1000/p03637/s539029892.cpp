#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  int F=0;
  int T=0;
  int O=0;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]%4==0){
      F++;
    }
    else if(A[i]%2==0){
      T++;
    }
    else{
      O++;
    }
  }
  bool flag=true;
  if(T!=0){
    if(O>F){
      flag=false;
    }
  }
  else{
    if(O>F+1){
      flag=false;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
  