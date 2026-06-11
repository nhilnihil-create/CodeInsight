#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,A,B;string S;
  
  cin>>N>>A>>B>>S;
  
  
  int check=0;
  
  int B_check=0;
  
  for(int i=0;i<N;i++){
    if(S[i]=='c'){
      cout<<"No"<<endl;
    }
    else if(S[i]=='a'){
      if(check<A+B){
        cout<<"Yes"<<endl;
        check++;
      }
      else if(check=A+B){
        cout<<"No"<<endl;
      }
    }
    else if(S[i]=='b'){
      if(check<A+B&&B_check<B){
        cout<<"Yes"<<endl;
        check++;
        B_check++;
      }
      else{
        cout<<"No"<<endl;
      }
    }
  }
}