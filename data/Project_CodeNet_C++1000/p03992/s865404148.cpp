#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  char s[16];
  for(int i=0;i<12;i++){
    cin>>s[i];
    char a=s[i];
    cout<<a;
    if(i==3)
      cout<<" ";
  }
  cout<<endl;
}