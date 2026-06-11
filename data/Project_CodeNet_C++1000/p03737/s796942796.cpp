#include<bits/stdc++.h>
using namespace std;
int main(){
  string A,B,C;
  cin>>A>>B>>C;
  string ANS="ANS";
  ANS.at(0)=A.at(0)-'a'+'A';
  ANS.at(1)=B.at(0)-'a'+'A';
  ANS.at(2)=C.at(0)-'a'+'A';
  cout<<ANS<<endl;
}
