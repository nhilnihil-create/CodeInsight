#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  string s;
  cin >> n >> a >> b >> s;
  int bcn=0,acn=0;
  for(int i=0;i<n;i++){
    if(s.at(i)=='c'){
      cout << "No"  << endl;
    }else if(s.at(i)=='b'){
      if(bcn<b&&acn<a+b){
        cout << "Yes" << endl;
        acn++;
        bcn++;
      }else{
        cout << "No" << endl;
      }
    }else{
      if(acn<a+b){
        cout << "Yes" << endl;
        acn++;
      }else{
        cout << "No" << endl;
      }
    }
  }
  return 0;
}