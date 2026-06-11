#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b,c;
  cin>>a>>b>>c;
  int dif='A'-'a';
  cout<<(char)(a[0]+dif)<<(char)(b[0]+dif)<<(char)(c[0]+dif)<<endl;
}