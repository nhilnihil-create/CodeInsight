#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,A,B;
  cin>>n>>A>>B;
  string s;
  cin>>s;
  int as=0,bs=0;
  for(int i=0;i<n;i++){
    if(s.at(i)=='a'&&as+bs<A+B){
      cout<<"Yes"<<endl;
      as++;
    }
    else if(s.at(i)=='b'&&as+bs<A+B&&bs<B){
      cout<<"Yes"<<endl;
      bs++;
    }
    else{
      cout<<"No"<<endl;
    }
  }

}