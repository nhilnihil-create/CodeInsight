// author: vinoda
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  string s;
  cin>>n>>a>>b>>s;
  int f_counter=0, total=0;
  for(int i=0; i<n; ++i){
    if((s[i]=='a')&&(total<(a+b))){
     cout<<"Yes"<<endl;
     ++total;
   }
    else if((s[i]=='b')&&(total<(a+b))&&(f_counter<b)){
      cout<<"Yes"<<endl;
      ++f_counter; 
      ++total;
    }
    else cout<<"No"<<endl;
  }
}
