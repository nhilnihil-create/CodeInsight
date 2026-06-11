#include<iostream>
#include<string>
using namespace std;

int main(){
  long N,A,B,i,j=0;
  string S;
  cin >> N >> A >> B;
  cin >> S;
  bool can = false;
  for(i=0;i<N;i++){
    if(S[i]=='b'){
      j++;
    }
    if(S[i]!='c' && i+1<=A+B){
      if(S[i]=='a'){
        can = true;
      }else if(j<=B){
        can = true;
      }else{
        A++;
      }
    }else{
      A++;
    }
    if(can){
    	cout << "Yes" << endl;
  	}else{
    	cout << "No" << endl;
  	}
    can = false;
  }
  return 0;
}