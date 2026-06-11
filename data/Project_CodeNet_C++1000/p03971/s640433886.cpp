#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  string s;
  cin >> n >> a >> b >> s;
  int abroad=0,pass=0;
  for(int i=0;i<n;i++){
    if(s[i]=='c'){
      cout << "No" << endl;
      continue;
    }
    if(s[i]=='a'){
      if(pass < (a+b)){
        cout << "Yes" << endl;
        pass++;
      }else{
        cout << "No" << endl; 
      }
    }
    if(s[i]=='b'){
      abroad++;
      if(pass < (a+b) && abroad <= b){
        cout << "Yes" << endl;
        pass++;
      }else{
        cout << "No" << endl;
      }
    }
  }
}