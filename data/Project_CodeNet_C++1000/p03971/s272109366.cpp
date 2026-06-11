#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,A,B;
  cin>>N>>A>>B;
  vector<char> a(N);
  int allp=0;
  int bp=0;
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  for(int i=0;i<N;i++){
    if(a.at(i)=='a'&&allp<A+B){
      cout<<"Yes"<<endl;
      allp++;
      continue;
    }
    if(a.at(i)=='a'&&allp>=A+B){
      cout<<"No"<<endl;
      continue;
    }
    if(a.at(i)=='b'&&(allp<A+B&&bp<B)){
      cout<<"Yes"<<endl;
      allp++;
      bp++;
      continue;
    }
    if(a.at(i)=='b'&&(allp>=A+B||bp>=B)){
      cout<<"No"<<endl;
      continue;
    }
    if(a.at(i)=='c'){
      cout<<"No"<<endl;
      continue;
    }
  }
}