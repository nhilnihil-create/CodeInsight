#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0,A=0,B=0;
  cin>>N>>A>>B;
  string S;
  cin>>S;
  int count=0;
  int countb=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='a'&&count<(A+B)){
        count+=1;
        cout<<"Yes"<<endl;
    }
    else if(S.at(i)=='b'&&count<(A+B)&&countb<B){
        count+=1;
        countb+=1;
        cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}