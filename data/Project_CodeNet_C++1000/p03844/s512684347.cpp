#include<bits/stdc++.h>
using namespace std;

int main(){
 string math;
 int a,b ; 
  cin >> a >> math >>b;
 if(math.at(0)=='+'){
   a=a+b;
 }else{
   a=a-b;
 } 
 cout << a << endl;
}
