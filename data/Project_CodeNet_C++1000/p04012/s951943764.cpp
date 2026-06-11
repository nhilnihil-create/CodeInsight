#include<bits/stdc++.h>
using namespace std;
int main(){
  int count[26]={0};
  char s;
  while(cin >> s){
    int num=s-'a';
    for(char i='a';i<='z';i++)if(s==i)count[num]++;
  }
  bool g=true;
  for(int i=0;i<26;i++){
    if(count[i]%2!=0){
      g=false;
      break;
    }
  }
  if(g)cout << "Yes" << endl;
  else cout << "No"  << endl;
}