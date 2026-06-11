#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if (A>B & A>C & A == B+C){
     cout<<"Yes"<<endl;
  }
   else if (B>C & B>A & B == A+C){
     cout<<"Yes"<<endl;
  }
  else if (C>B & C>A & C == A+B){
     cout<<"Yes"<<endl;
  }
  else{
     cout<<"No"<<endl;
  }
  
  
}
