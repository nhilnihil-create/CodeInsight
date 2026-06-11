#include <bits/stdc++.h>
using namespace std;
 

int main() {
  string s;
  cin>>s;
  

  int N=(s.size()+1)/2;
  string word;
  for(int i=0;i<N;i++){
    word=word+s.at(2*i);
  }
  
  cout<<word<<endl;
}