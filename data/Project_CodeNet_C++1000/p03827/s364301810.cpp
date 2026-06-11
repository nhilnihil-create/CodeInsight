#include <bits/stdc++.h>
using namespace std;
 
int main() {
int n;
  string s;
  cin>>n>>s;
 int count=0,totori=0;
  
  for(int i=0;i<n;i++){
  if(s.at(i)=='I' && count >=totori){
  count++; totori=count;}
 else if(s.at(i)=='I' && count < totori)
   count++;
    else count--;
  }
  cout <<totori<<endl;
}