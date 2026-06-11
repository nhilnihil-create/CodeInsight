#include <bits/stdc++.h>
using namespace std;
int main (){
  int H,W;
  cin>>H>>W;
  vector<string> line(H);
  for(int i=0;i<W+2;i++){
    cout<<"#";
  }
  cout<<endl;
  for(int i=0;i<H;i++){
    cin>>line.at(i);
    cout<<"#"+line.at(i)<<"#"<<endl;
  }
  for(int i=0;i<W+2;i++){
  cout<<"#";
  }  
}
