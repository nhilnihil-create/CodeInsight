#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int N,A,B;
  cin>>N>>A>>B;
  string s;
  cin>>s;
  int t=A+B,d=B;
  for(int i=0;i<N;i++){
    if(t>0){
      if(s[i]=='a'){cout<<"Yes"<<endl;t--;}
      else if(s[i]=='b'&&0<d){cout<<"Yes"<<endl;t--;d--;}
      else{cout<<"No"<<endl;}
    }
    else{cout<<"No"<<endl;}
  }
  return 0;
}