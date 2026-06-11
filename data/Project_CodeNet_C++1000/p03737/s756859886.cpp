#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<string> a(3);
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  string t_1="abcdefghijklmnopqrstuvwxyz";
  string t_2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i=0;i<3;i++){
    for(int j=0;j<26;j++){
      if(a[i][0]==t_1[j]){
        cout<<t_2[j];
      }
    }
  }
}