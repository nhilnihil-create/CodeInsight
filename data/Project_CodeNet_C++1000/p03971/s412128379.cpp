#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;
  cin >> N >> A >> B;
  string s;
  cin>>s;
  int a=0;
  int b=1;
  for(int i=0;i<N;i++){
    if(s[i]=='a'){
      if(a<A+B){
        cout << "Yes" << endl;
        a++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else if(s[i]=='b'){
      if(a<A+B && B>=b){
        cout << "Yes" << endl;
        a++;
        b++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else{
      cout << "No" << endl;
    }
  }
}
