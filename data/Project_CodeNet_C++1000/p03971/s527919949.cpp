#include<iostream>
#include <string>
using namespace std;
int main(){
  int N;
  int A;
  int B;
  string S;
  string S1;
  cin>>N>>A>>B;
  cin>>S;
  int i;
  int foreignrank=1;
  int passpeople=0;
  for(i=0;i<=N-1;i++){
  S1=S[i];
  if(S1=="a"){
  	if(passpeople<A+B){
  		cout<<"Yes"<<endl;
  		passpeople++;
  	}
    else{
        cout<<"No"<<endl;
    }
  }
  else if(S1=="b"){
    if(passpeople<A+B){
    	if(foreignrank<=B){
    		cout<<"Yes"<<endl;
            passpeople++;
    	}
    	else{
    		cout<<"No"<<endl;
    	}
    }
    else{
    	cout<<"No"<<endl;
    }
    foreignrank++;
  }
  else if(S1=="c"){
  cout<<"No"<<endl;
  }
  }
}