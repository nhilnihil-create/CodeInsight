#include<bits/stdc++.h>
using namespace std;

string a;
bool ada=false;
int sol;

int main(){
  cin>>a;
  for(int i=a.length()-2;i>=0;i--){
    if(i%2==1){
      if(a.substr(0,(i+1)/2) == a.substr((i+1)/2,(i+1)/2)){
        sol=i+1;
        ada=true;
        break;
      }
    }
  }
  if(ada){
    cout<<sol;
  }
  else{
    cout<<-1;
  }
}
    