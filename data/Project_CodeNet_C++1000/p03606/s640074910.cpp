#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int result=0;
  for(int i=0;i<n;i++){
    int f,s;
    cin>>f>>s;
    result+=s-f+1;
  }
  cout<<result;
  
}