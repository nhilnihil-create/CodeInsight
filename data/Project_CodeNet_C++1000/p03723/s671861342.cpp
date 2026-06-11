#include <bits/stdc++.h>
using namespace std;

void cookie(int &a,int &b,int &c,bool &same,bool &check){
  int S=a+b+c;
  if(a!=b || b!=c || c!=a){
  a= (S-a)/2;
  b= (S-b)/2;
  c= (S-c)/2;
    if(a+b+c!=S){
      check=false;
    }
  }else if(a%2==1){
    check = false;
  }else{
    same = true;
  }
}
    
int main(){
  int A,B,C;
  cin >> A >> B >> C;
  int sum = A+B+C;
  int count = -1;
  bool check=true;
  bool same = false;
  while(check==true && same == false){
    count++;
    cookie(A,B,C,same,check);
  }
  if(!(same)){
  cout << count << endl;
  }else{
    cout << -1 << endl;
  }
}
